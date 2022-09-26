/*
 * 01-SimpleCounter.ino
 * Author: Liam Davies (l.davies@diyodemag.com)
 * Copyright (c) 2022 DIYODE Magazine
 */

#include "DIYsplay.h"

//Initialises our DIYsplay variable.
DIYsplay diysplay = DIYsplay();

void setup() {
  //Starts the DIYsplay.
  diysplay.begin();

  //Sets the screen to the LED counter.
  diysplay.setScreen(LARGE_LEDDIGITS_RED);
}

void loop() {
  //Puts a increasing counter on the screen in seconds.
  diysplay.setData(0, millis() / 1000);

  //Wait one second before we update the screen again.
  delay(1000);
}