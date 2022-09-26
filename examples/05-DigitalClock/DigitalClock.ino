#include "DIYsplay.h"
#include "RTClib.h"
#include "SPI.h"

RTC_DS1307 rtc;

//Initialises our DIYsplay variable.
DIYsplay diysplay = DIYsplay();

void setup() {
  Serial.begin(9600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  //Starts the DIYsplay.
  diysplay.begin();
  diysplay.setScreen(DIGITAL_CLOCK);
}

const char *daysOfWeek[] = {"SUNDAY", "MONDAY", "TUESDAY", 
                            "WEDNESDAY", "THURSDAY", 
                            "FRIDAY", "SATURDAY"};

void loop() {
  DateTime time = rtc.now();

  diysplay.setData(0, time.twelveHour());
  diysplay.setData(1, time.minute());
  diysplay.setData(2, time.second());

  diysplay.setData(3, daysOfWeek[time.dayOfTheWeek()]);

  delay(1000);
}