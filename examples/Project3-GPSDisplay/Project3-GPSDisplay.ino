#include "TinyGPS++.h"
#include <SoftwareSerial.h>
#include "DIYsplay.h"

DIYsplay diysplay = DIYsplay();

static const int RXPin = 9, TXPin = 8;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

double old_longitude;
double old_latitude;
double longitude;
double latitude;

void setup()
{
  diysplay.begin();
  diysplay.setScreen(COMPASS_WITH_LONGITUDE_LATITUDE);
  diysplay.setData(1, "Searching");
  diysplay.setData(2, "Searching");

  Serial.begin(115200);
  ss.begin(GPSBaud);
}

void loop()
{
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0)
    if (gps.encode(ss.read())) {
      displayInfo();
      delay(2000);
      
      diysplay.listen();
      diysplay.setData(1, String(longitude,5));
      diysplay.setData(2, String(latitude,5));
      double heading = gps.courseTo(old_latitude, old_longitude, latitude, longitude);
      Serial.print(" Heading: ");
      Serial.print(heading);
      diysplay.setData(0, heading);
      
      ss.listen();
  }

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}

void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    old_longitude = longitude;
    old_latitude = latitude;
    longitude = gps.location.lng();
    latitude = gps.location.lat();

    Serial.print(gps.location.lat(), 6);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 6);
  }
  else
  {
    longitude = -1;
    latitude = -1;
    Serial.print(F("INVALID"));
  }

  Serial.println();
}
