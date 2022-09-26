#include "DIYsplay.h"
DIYsplay diysplay = DIYsplay();

void setup() {
  // put your setup code here, to run once:
  diysplay.begin();
  diysplay.setScreen(DIGITAL_CLOCK);
  diysplay.setData(0, 2);
  diysplay.setData(1, 30);
  diysplay.setData(2, 51);
  diysplay.setData(3, "Hello World!");

}

void loop() {
  // put your main code here, to run repeatedly:

}
