#include "WaterLevel.h"
#include "Config.h"
#include <Arduino.h>
#define WL_MAX 3.0
#define WL_2 5.0

extern Status currentStatus;

WaterLevel::WaterLevel(int trigPin, int echoPin, unsigned long period, int ledPin) : Task(period) {
    this->sonar = new Sonar(trigPin, echoPin);
    this->led = new Led(ledPin);
}

void WaterLevel::toExecute() {
    unsigned long currentTime = millis();
    if (currentTime - this->elapsedTime >= this->getPeriod()) {
        double currDistance = this->sonar->getDistance();
        if (currDistance >= WL_MAX) {
            currentStatus = ALARM;
        } else if (currDistance >= WL_2) {
            currentStatus = PRE_ALARM;
            led -> turnOn();
        } else {
            currentStatus = NORMAL;
            led -> turnOn();
        }
    }
    this->elapsedTime = currentTime;
}