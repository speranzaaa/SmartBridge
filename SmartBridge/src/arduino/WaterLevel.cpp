#include "WaterLevel.h"
#include "Config.h"
#include <Arduino.h>

extern Status currentStatus;
extern double waterDistance;

WaterLevel::WaterLevel(int trigPin, int echoPin, unsigned long period, int ledPin) : Task(period) {
    this->sonar = new Sonar(trigPin, echoPin);
    this->led = new Led(ledPin);
}

void WaterLevel::toExecute() {
    unsigned long currentTime = millis();
    if (currentTime - this->elapsedTime >= this->getPeriod()) {
        double currDistance = this->sonar->getDistance();
        #ifdef __DEBUG__
        Serial.print("Current water level: ");
        Serial.println(currDistance);
        #endif
        if (currDistance <= WL_MAX) {
            currentStatus = ALARM;
            this->led->turnOff();
            this->setPeriod(PE_ALARM);
        } else if (currDistance <= WL_2) {
            currentStatus = PRE_ALARM;
            this->led->turnOn();
            this->setPeriod(PE_PREALARM);
        } else {
            currentStatus = NORMAL;
            this->led->turnOn();
            this->setPeriod(PE_NORMAL);
        }
        waterDistance = currDistance;
    }
    this->elapsedTime = currentTime;
}