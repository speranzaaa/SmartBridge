#include "Valve.h"
#include <Arduino.h>
#include "Config.h"
// #include "EnableInterrupt.h"

extern Status currentStatus;
extern volatile bool manual;
extern double waterDistance;
extern int valveOpening;


Valve::Valve(int potPin, int servoPin, unsigned long period) : Task(period) {
    this->servoPin = servoPin;
    this->pot = new Pot();
}

void Valve::toExecute() {
    Serial.println("Valve::toExecute()");

    if (currentStatus == ALARM) {
        switch (manual)
        {
        case false:
            if (waterDistance == 0) {
                valveOpening = 180;
                //this->servo.write(97);
                Serial.println("VALARM - AUTO");
                break;
            } else {
                valveOpening = 180*(waterDistance)/WL_MAX;
                this->servo.attach(this->servoPin);
                this->servo.write(valveOpening);
                this->servo.detach();
                break;
            };
        case true:
            this->servo.write(this->pot->getValveValue());
            break;
        }
    }
}


