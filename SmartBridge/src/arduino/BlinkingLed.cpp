#include "BlinkingLed.h"
#include <Arduino.h>
#include "Config.h"
#define BLINKING_TIME 2000
extern Status currentStatus;

BlinkingLed::BlinkingLed(unsigned long period, int ledPin) : Task(period) {
    this->led = new Led(ledPin);
}

void BlinkingLed::toExecute() {
    unsigned long currentTime = millis();
    switch (currentStatus) {
    case NORMAL:
        this->led->turnOff();
        this->wasNormal = true;
        #ifdef __DEBUG__
        Serial.println("Status is normal, turning off red led.");
        #endif
        break;

    case PRE_ALARM:
        if (this->led->isOn() && currentTime - this->lastActionTime >= BLINKING_TIME) {
            #ifdef __DEBUG__
            Serial.println("Pre-alarm status, turning off red led.");
            #endif
            this->led->turnOff();
            this->lastActionTime = currentTime;
        } else if (!this->led->isOn() && currentTime - this->lastActionTime >= BLINKING_TIME) {
            #ifdef __DEBUG__
            Serial.println("Pre-alarm status, turning on red led.");
            #endif
            this->led->turnOn();
            this->lastActionTime = currentTime;
        } else if (this->wasNormal && !this->led->isOn()) {
            #ifdef __DEBUG__
            Serial.println("Pre-alarm status, turning on red led.");
            #endif
            this->led->turnOn();
            this->lastActionTime = currentTime;
        }
        this->wasNormal = false;
        break;

    case ALARM:
        #ifdef __DEBUG__
        Serial.println("Alarm status, turning on red led.");
        #endif
        this->led->turnOn();
        this->wasNormal = false;
        break;
    }
}