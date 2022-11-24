#include "Valve.h"
#include <Arduino.h>
#include "Config.h"

extern Status currentStatus;
extern bool manual;
extern double waterDistance;

Valve::Valve(int potPin, int servoPin, unsigned long period) : Task(period) {
    this->potPin = potPin;
    this->servoPin = servoPin;
}

void Valve::toExecute() {
    if (currentStatus == ALARM) {
        switch (manual)
        {
        case false:

            break;
        
        case true:
            break;
        }
    }
}
