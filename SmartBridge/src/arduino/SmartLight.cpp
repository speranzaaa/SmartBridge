#include "SmartLight.h"
#include <Arduino.h>
#include "Config.h"
extern bool debug;
#define LIGHT_TIME 10000

extern Status currentStatus;

SmartLight::SmartLight(int lightPin, int lightSensorPin, int pirPin, int period) : Task(period) {
    this->bridgeLight = new Led(lightPin);
    this->lightSensor = new LightSensor(lightSensorPin);
    this->pir = new Pir(pirPin);
}

void SmartLight::toExecute() {
    unsigned long currentTime = millis();
    switch (currentStatus) {
    case NORMAL:
    case PRE_ALARM:
        // If movement detected, turn light on based on light level and stay on for LIGHT_TIME
        if (!this->lightSensor->isDay()) {
            if (debug) Serial.println("Night detected, turning off bridge light.");
            this->bridgeLight->turnOff();
        } else if (this->pir->isDetected() && this->lightSensor->isDay()) {
            if (debug) Serial.println("Movement detected during day, turning on brigde ligth.");
            this->timeDetected = currentTime;
            this->bridgeLight->turnOn();
        } else if (currentTime - this->timeDetected >= LIGHT_TIME) {
            if (debug) Serial.println("Light time expired, turning off bridge light.");
            this->bridgeLight->turnOff();
        }
        break;
    
    case ALARM:
        if (debug) Serial.println("Alarm state, turning off brigde light.");
        this->bridgeLight->turnOff();
        break;
    }
}
