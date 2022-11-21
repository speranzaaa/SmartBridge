#include "SmartLight.h"
#include <Arduino.h>

SmartLight::SmartLight(int La, int Pir, int LS, int period)
{
    this->La = La;
    this->Pir = Pir;
    this->LS = LS;
    this->period = period;
    pinMode(La, OUTPUT);
    pinMode(Pir, INPUT);
    pinMode(LS, INPUT);
}

void SmartLight::tick()
{
    Serial.println("prova");
}

void SmartLight::removeTask()
{

}