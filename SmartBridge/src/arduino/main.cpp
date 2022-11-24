#include <Arduino.h>
#include "Config.h"
#include "MsgService.h"
#include "Valve.h"
#include "Task.h"
#include "EnableInterrupt.h"
#include "ButtonInterrupt.h"

bool debug = false;

Status currentStatus = ALARM;
volatile bool manual = true; 
double waterDistance;

Task* valve;

void setup() {
    Serial.begin(9600);
    valve = new Valve(A0, 6, 200);
    enableInterrupt(2, buttonInt, HIGH);
}

void loop() {
    valve->tick();
    delay(50);
}

