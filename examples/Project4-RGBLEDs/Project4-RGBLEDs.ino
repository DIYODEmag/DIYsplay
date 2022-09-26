#include "Adafruit_NeoPixel.h"
#include "DIYsplay.h"

DIYsplay diysplay = DIYsplay();
#define LED_COUNT 8
#define LED_PIN 8

//We're using a normal GPIO pin as 5V power. You can just hook the +5V power on the Joystick
//up to the Arduino any way you want, we've just done this so it's less confusing to look at.
#define POWER_JOYSTICK_PIN A0
#define JOYSTICK_X_PIN A1
#define JOYSTICK_BUTTON A3

#define MIN_MOVE 200

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//Mode 0 = RGB LED screen
//Mode 1 = LED Selection Screen
byte mode = 0;
byte selected_led = 0;
uint16_t colour_wheel = 0;

void setup() {
  pinMode(POWER_JOYSTICK_PIN, OUTPUT);
  digitalWrite(POWER_JOYSTICK_PIN, HIGH);

  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);
  
  diysplay.begin();
  strip.begin();

  diysplay.setScreen(COLOUR_LED_WITH_GAUGES);
}

void loop() {
  // put your main code here, to run repeatedly:
  int joystickDir = 0;
  if(analogRead(JOYSTICK_X_PIN) > 512 + MIN_MOVE) {
    joystickDir = 1;
  } else if (analogRead(JOYSTICK_X_PIN) < 512 - MIN_MOVE) {
    joystickDir = -1;
  }

  if(!digitalRead(JOYSTICK_BUTTON)) {
    if(mode == 0) {
      mode = 1;
      diysplay.setScreen(_8_X_FLAT_ROUND_LED);
    } else if (mode == 1) {
      mode = 0;
      diysplay.setScreen(COLOUR_LED_WITH_GAUGES);
    }
    delay(500);
    
  }

  if(mode == 0) { 
    uint32_t colour = strip.ColorHSV(colour_wheel);
    setColour((byte)(colour >> 16), (byte)(colour >> 8), (byte)(colour >> 0));
    strip.setPixelColor(selected_led, colour);
    strip.show();
    if(joystickDir == 1) {
      colour_wheel += 1000;
    } else if(joystickDir == -1) {
      colour_wheel -= 1000;
    }
    
    delay(5);
  } else if (mode == 1) {
    for(int i = 0; i < LED_COUNT; i++) {
      diysplay.setData(i, i == selected_led ? 1 : 0);
    }

    if(joystickDir) {
      selected_led += joystickDir;
      selected_led %= 8;
      delay(100);
    } 
  }

  
}

void setColour(byte r, byte g, byte b) { 
  uint16_t colour = 0;
  colour |= (r >> 3) << 0;
  colour |= (g >> 2) << 5;
  colour |= (b >> 3) << 11;
  diysplay.setData(0, colour);
  //Blue
  diysplay.setData(1, b);
  diysplay.setData(4, b);

  //Green
  diysplay.setData(2, g);
  diysplay.setData(5, g);

  //Red
  diysplay.setData(3, r);
  diysplay.setData(6, r);
}