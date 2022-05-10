#include "PlantMonitor.h"

PlantMonitor pm = PlantMonitor(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'l') {
      pm.ledOff();
    }
    else if (cmd == 'L') {
      pm.ledOn();
    }
  }
  report();
  delay(1000);
}

void report() {
  Serial.print("Wetness: ");
  Serial.print(pm.getWater());
  Serial.print(" temp (C): ");
  Serial.print(pm.getTemp());
  Serial.print(" humidity: ");
  Serial.println(pm.getHumidity());
}
