#include "Valve.h"
#include <Arduino.h>
#include "Config.h"

Valve::Valve(int potPin, int servoPin, unsigned long period) {
    this->potPin = potPin;
    this->servoPin = servoPin;
    this->init(period);
}

void Valve::toExecute() {
    servo->on();
    for (int i = 0; i < 180; i++) {
        Serial.println(pos);
        servo->setPosition(pos);           
        pos += delta;
    }
    servo->off();
    pos -= delta;
    delta = -delta;
    delay(1000);
}