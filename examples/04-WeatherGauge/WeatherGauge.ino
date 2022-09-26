#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include "DIYsplay.h"

#define DHTPIN 2
#define DHTTYPE    DHT11

DHT_Unified dht(DHTPIN, DHTTYPE);

//Initialises our DIYsplay variable.
DIYsplay diysplay = DIYsplay();

void setup() {
  pinMode(A0, INPUT);

  //Starts the DIYsplay.
  diysplay.begin();

  //Starts the temperature sensor
  dht.begin();

  //Sets the screen to display the temperature and humidity gauges.
  diysplay.setScreen(TEMPERATURE_HUMIDITY_WITH_TEXT_AREAS);
  //Sets the titles of both areas.
  diysplay.setData(4,"Temp");
  diysplay.setData(5,"RH");
}

void loop() {
  //Polls events from the sensor
  sensors_event_t event;

  //If we get a temperature event, put it on the display.
  dht.temperature().getEvent(&event);
  if (!isnan(event.temperature)) {
    diysplay.setData(0,event.temperature);
    //Note we need to multiply the reading by 10 as there is a decimal point here.
    diysplay.setData(1,event.temperature*10);
  }

  //Same process for the humidity data.
  dht.humidity().getEvent(&event);
  if (!isnan(event.relative_humidity)) {
    diysplay.setData(2,event.relative_humidity);
    diysplay.setData(3,event.relative_humidity);
  }

  //The DHT11 module we have can only poll at 1Hz, so give it some time to relax.
  delay(1000);
}