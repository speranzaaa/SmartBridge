#include "lightSensor.h"
#include <Arduino.h>
#include <string.h>
#define DAYLIGHT 50
extern bool debug;

LightSensor::LightSensor(int pin) {
    this->pin = pin;
    pinMode(this->pin, INPUT);
}

bool LightSensor::isDay() {
    int lightLevel = this->getLightLevel();
    if (debug) {
        Serial.print("light level detected: ");
        Serial.print(lightLevel);
        Serial.print(", daylight threshold: ");
        Serial.print(DAYLIGHT);
    }
    return lightLevel > DAYLIGHT;
}

int LightSensor::getLightLevel() {
    return analogRead(this->pin);
}