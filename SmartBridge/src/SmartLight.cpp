#include "SmartLight.h"
#include <Arduino.h>

SmartLight::SmartLight(int La, int Pir, int LS, int period)
{
    this->La = La;
    this->Pir = Pir;
    this->LS = LS;
    this->init(period);
    pinMode(La, OUTPUT);
    pinMode(Pir, INPUT);
    pinMode(LS, INPUT);
}

@override
SmartLight::tick()
{

}