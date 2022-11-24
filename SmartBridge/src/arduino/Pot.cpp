#include "Pot.h"
#include <Arduino.h>
#include "Config.h"
#define POT_LOW_BOUND 0
#define POT_UP_BOUND 1023
#define VALVE_LOW_BOUND 0
#define VALVE_UP_BOUND 180

int Pot::getValveValue() {
    int value = analogRead(POT_PIN);
    long valveRad = map(value, POT_LOW_BOUND, POT_UP_BOUND, VALVE_LOW_BOUND, VALVE_UP_BOUND);
    return (int)valveRad;
}
