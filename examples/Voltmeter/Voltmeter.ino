/*
 * Voltmeter.ino
 * Author: Liam Davies (l.davies@diyodemag.com)
 * Copyright (c) 2022 DIYODE Magazine
 */

//NOTE: Despite the graph displaying a 10V maximum range,
//do NOT apply a voltage of over 5V to the Arduino's input!

#include "DIYsplay.h"

//Initialises our DIYsplay variable.
DIYsplay diysplay = DIYsplay();

#define INPUT_VOLTAGE_PIN A0

void setup() {
  //Sets up the analog input pin.
  pinMode(INPUT_VOLTAGE_PIN, INPUT);

  //Starts the DIYsplay.
  diysplay.begin();

  //Sets the screen to the Voltmeter.
  diysplay.setScreen(VOLTMETER_BLACK);
}

void loop() {
  //This line converts a signal on the input pin to a 0-5V range.
  float inputVoltage = 5 * analogRead(INPUT_VOLTAGE_PIN) / 1024.0;

  //Displays the voltage on the screen. The first line sets the LED digits,
  //and the second line sets the analog gauge itself.
  //Note that we need to multiply everything by 10 as the decimal point isn't included.
  diysplay.setData(0, inputVoltage * 10);
  diysplay.setData(1, inputVoltage * 10);

  //A short delay before we fetch a new voltage again.
  delay(200);
}