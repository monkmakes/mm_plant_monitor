#include "Arduino.h"
#include "PlantMonitor.h"

PlantMonitor::PlantMonitor(uint8_t rxPin, uint8_t txPin) : _sensor(rxPin, txPin) {
  _sensor = SoftwareSerial(rxPin, txPin);
  _sensor.begin(9600);
}

int PlantMonitor::getWater() {
  _sensor.print("w");
  while (! _sensor.read() == '=') {};
  return _sensor.parseInt();
}

float PlantMonitor::getTemp() {
  _sensor.print("t");
  while (! _sensor.read() == '=') {};
  return _sensor.parseFloat();
}

float PlantMonitor::getHumidity() {
  _sensor.print("h");
  while (! _sensor.read() == '=') {};
  return _sensor.parseFloat();
}

void PlantMonitor::ledOn() {
  _sensor.print("L");
}

void PlantMonitor::ledOff() {
  _sensor.print("l");
}
