#include "pir.hpp"
#include "Arduino.h"

Pir::Pir(unsigned int pin)
{
    this->pin = pin;
    pinMode(this->pin, INPUT);
    delay(this->CALIBRATION_TIME);
}

bool Pir::isDetected()
{
    return digitalRead(this->pin) == HIGH;
}