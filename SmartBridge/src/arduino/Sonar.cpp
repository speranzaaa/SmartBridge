#include "Sonar.hpp"
#include <Arduino.h>

Sonar::Sonar(unsigned int trigPin, unsigned int echoPin)
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    this->trigPin = trigPin;
    this->echoPin = echoPin;
}

double Sonar::getDistance()
{
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(3);
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(5);
    digitalWrite(this->trigPin, HIGH);

    long tUS = pulseInLong(echoPin, HIGH);
    double t = tUS / 1000.0 / 1000.0 / 2;
    return t * this->SOUNDSPEED;
}