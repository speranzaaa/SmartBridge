#include "Valve.h"
#include <Arduino.h>
#include "Config.h"
// #include "EnableInterrupt.h"

extern Status currentStatus;
extern volatile bool manual;
extern double waterDistance;


Valve::Valve(int potPin, int servoPin, unsigned long period) : Task(period) {
    this->servoPin = servoPin;
    this->servo.attach(this->servoPin);
    this->pot = new Pot();
}

void Valve::toExecute() {
    Serial.println("Valve::toExecute()");
    if (currentStatus == ALARM) {
        switch (manual)
        {
        case false:
            // TODO Automatic valve opening
            break;
        
        case true:
            this->servo.write(this->pot->getValveValue());
            break;
        }
    }
}
