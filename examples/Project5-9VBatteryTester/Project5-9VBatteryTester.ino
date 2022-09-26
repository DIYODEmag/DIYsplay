#include "DIYsplay.h"

#define BATTERY_PIN A0
#define MIN_BAT_VOLTAGE 6.5
#define MAX_BAT_VOLTAGE 9.5

DIYsplay diysplay = DIYsplay();

void setup() {
  pinMode(BATTERY_PIN, INPUT);

  //Starts the DIYsplay.
  diysplay.begin();

  diysplay.setScreen(BATTERY_LEVEL_GAUGE_BLUE);
}

void loop() {
  double reading = analogRead(BATTERY_PIN);
  // We're using a voltage divider, which is half of the input voltage.
  // Our Arduino can read a maximum of 5V, so factor that in.
  // Finally, we have an input range of 0-1023 so include that.
  reading *= 2.0 * 5.0 / 1023.0;

  // Map the voltage of the battery to a value between 0 and 100.
  double percentage = map(reading, MIN_BAT_VOLTAGE, MAX_BAT_VOLTAGE, 0.0, 100.0);
  percentage = constrain(percentage, 0, 100);
  diysplay.setData(0, percentage);
  
  // We need to multiply this by 10 to compensate for the decimal point.
  diysplay.setData(1, reading * 10);
  
}
