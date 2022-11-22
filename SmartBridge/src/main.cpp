#include <Arduino.h>
#include "BlinkingLed.h"
#include "Config.h"
bool debug = false;

Status currentStatus = NORMAL;
int x;

void setup() {
    Serial.begin(9600);
  Serial.setTimeout(1);
}

void loop() {
    while (!Serial.available());
    x = Serial.readString().toInt();
    Serial.print(x + 1);
}
