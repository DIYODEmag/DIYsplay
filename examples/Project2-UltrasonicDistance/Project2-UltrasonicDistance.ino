#include "DIYsplay.h"
DIYsplay diysplay = DIYsplay();

#define ECHO_PIN 9
#define TRIG_PIN 8

void setup() {
  //Initialises the ECHO and TRIGGER pins.
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);

  //Starts the DIYsplay.
  diysplay.begin();
  diysplay.setScreen(RULER_GAUGE_TAPE_COMPASS);
}

void loop() {
  //Create a trigger pulse.
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  //Calculate the distance to the object we hit.
  double duration = pulseIn(ECHO_PIN, HIGH);
  double distance = duration * 0.034 / 2.0;
  
  //Write the data to the DIYsplay.
  diysplay.setData(0,distance * 10.0);
  distance = constrain(distance, 0, 100);
  diysplay.setData(1,distance); 

  delay(100);
}
