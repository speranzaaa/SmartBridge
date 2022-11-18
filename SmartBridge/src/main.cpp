#include <Arduino.h>
#include "SmartLight.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Task* prova = new SmartLight(1, 2, 3, 1000);
  prova->tick();
  delete prova;
}

void loop() {
  // put your main code here, to run repeatedly:
}