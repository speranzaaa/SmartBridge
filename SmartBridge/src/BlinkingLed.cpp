#include "BlinkingLed.h"
#include <Arduino.h>
#include "config.h"
#define BLINKING_TIME 2000
extern bool debug;
extern Status currentStatus;

BlinkingLed::BlinkingLed(unsigned long period, int ledPin) {
    this->init(period);
    this->led.setPin(ledPin);
}

void BlinkingLed::tick() {
    unsigned long currentTime = millis();
    if (currentTime - this->elapsedTime >= this->getPeriod()) {
        switch (currentStatus) {
        case NORMAL:
            this->led.turnOff();
            if (debug)
                Serial.println("Status is normal, turning off red led.");
            break;

        case PRE_ALARM:
            if (this->led.isOn() && currentTime - this->lastActionTime >= BLINKING_TIME) {
                if (debug)
                    Serial.print("Pre-alarm status, turning off red led.");
                this->led.turnOff();
                this->lastActionTime = currentTime;
            } else if (!this->led.isOn() && currentTime - this->lastActionTime >= BLINKING_TIME) {
                if (debug)
                    Serial.println("Pre-alarm status, turning on red led.");
                this->led.turnOn();
                this->lastActionTime = currentTime;
            }
            break;

        case ALARM:
            if (debug)
                Serial.println("Alarm status, turning on red led.");
            this->led.turnOn();
            break;
        }
    }
}