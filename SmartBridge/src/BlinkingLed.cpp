#include "BlinkingLed.h"
#include <Arduino.h>
#include "config.h"
#define BLINKING_TIME 2000

extern Status currentStatus;

BlinkingLed::BlinkingLed(unsigned long period, int ledPin) {
    this->init(period);
    this->led.setPin(ledPin);
}

void BlinkingLed::tick() {
    unsigned long currentTime = millis();
    switch (currentStatus) {
    case NORMAL:
        this->led.turnOff();
        break;

    case PRE_ALARM:
        if (this->led.isOn() && currentTime - this->lastActionTime >= BLINKING_TIME) {
            this->led.turnOff();
            this->lastActionTime = currentTime;
        } else if (!this->led.isOn() && currentTime - this->lastActionTime >= BLINKING_TIME) {
            this->led.turnOn();
            this->lastActionTime = currentTime;
        }
        break;

    case ALARM:
        this->led.turnOn();
        break;
    }
}