#include "Task.h"
#include <Arduino.h>

void Task::init(unsigned long period) {
    this->period = period;
}

unsigned long Task::getPeriod() {
    return this->period;
}

void Task::tick() {
    unsigned long currentTime = millis();
    if (currentTime - this->elapsedTime >= this->getPeriod()) {
        this->toExecute();
    }
    this->elapsedTime = currentTime;
}