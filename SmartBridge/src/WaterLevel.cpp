#include "WaterLevel.h"
#include "config.h"
#include <Arduino.h>
#define WL_MAX 3.0
#define WL_2 5.0

extern Status currentStatus;

WaterLevel::WaterLevel(int trigPin, int echoPin, unsigned long period) {
    this->sonar = new Sonar(trigPin, echoPin);
    this->init(period);
}

void WaterLevel::toExecute() {
    unsigned long currentTime = millis();
    if (currentTime - this->elapsedTime >= this->getPeriod()) {
        double currDistance = this->sonar->getDistance();
        if (currDistance >= WL_MAX) {
            currentStatus = ALARM;
        } else if (currDistance >= WL_2) {
            currentStatus = PRE_ALARM;
        } else {
            currentStatus = NORMAL;
        }
    }
    this->elapsedTime = currentTime;
}