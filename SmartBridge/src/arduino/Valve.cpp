#include "Valve.h"
#include <Arduino.h>
#include "Config.h"

extern Status currentStatus;
extern bool manual;
extern double waterDistance;

Valve::Valve(int potPin, int servoPin, unsigned long period) : Task(period) {
    this->servoPin = servoPin;
    this->pot = new Pot(potPin);
}

void Valve::toExecute() {
    Serial.println("Valve::toExecute()");
    if (currentStatus == ALARM) {
        switch (manual)
        {
        case false:

            break;
        
        case true:
        Serial.println("Valve::toExecute() - manual");
            this->servo->on();
            this->servo->setPosition(this->pot->getValveValue());
            this->servo->off();
            break;
        }
    }
}
