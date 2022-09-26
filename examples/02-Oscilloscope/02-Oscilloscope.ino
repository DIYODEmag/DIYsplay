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

void setup() {
  pinMode(A0, INPUT);

  //Starts the DIYsplay.
  diysplay.begin();

  //Sets the screen to the Oscilloscope.
  diysplay.setScreen(FULL_SCOPE);
}

void loop() {

  //Displays a sine wave on the DIYsplay.
  //The Oscilloscope takes values between 0 and 80,
  //and displays a new point every time the setData() function
  //is called. We're displaying a sin wave scaled between the upper
  //and lower bounds of the scope here.

  diysplay.setData(0, 40+40*(float)sin(millis()/300.0));

  //Comment the above line and uncomment the line below
  //to plot A0 as an oscilloscope trace!
  //diysplay.setData(0, (80/1024.0) * analogRead(A0));
}