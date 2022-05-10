/*
  PlantMonitor.h - Library for the MonkMakes 
  Plant Monitor
  https://monkmakes.com/pmon
  MIT License
*/

#ifndef PlantMonitor_h
#define PlantMonitor_h

#include "Arduino.h"
#include <SoftwareSerial.h>

class PlantMonitor
{
  public:
    PlantMonitor(uint8_t rxPin, uint8_t txPin);
    int getWater();
    float getTemp();
    float getHumidity();
    void ledOn();
    void ledOff();
  private:
    SoftwareSerial _sensor;
};

#endif
