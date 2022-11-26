#include "SmartLight.h"
#include <Arduino.h>
#include "Config.h"
#define LIGHT_TIME 10000

extern Status currentStatus;
extern bool isLightOn;

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
        if (this->lightSensor->isDay()) {
            #ifdef __DEBUG__
            Serial.println("Day detected, turning off bridge light.");
            #endif
            this->bridgeLight->turnOff();
            isLightOn = false;
        } else if (this->pir->isDetected() && !this->lightSensor->isDay()) {
            #ifdef __DEBUG__
            Serial.println("Movement detected during night, turning on brigde light.");
            #endif
            this->timeDetected = currentTime;
            this->bridgeLight->turnOn();
            isLightOn = true;
        } else if (currentTime - this->timeDetected >= LIGHT_TIME) {
            #ifdef __DEBUG__
            Serial.println("Light time expired, turning off bridge light.");
            #endif
            this->bridgeLight->turnOff();
            isLightOn = false;
        }
        break;
    
    case ALARM:
        #ifdef __DEBUG__
        Serial.println("Alarm state, turning off brigde light.");
        #endif
        this->bridgeLight->turnOff();
        isLightOn = false;
        break;
    }
}
