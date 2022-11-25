#include <Arduino.h>
#include "Config.h"
#include "MsgService.h"
#include "Valve.h"
#include "Task.h"
#include "EnableInterrupt.h"
#include "ButtonInterrupt.h"
#include "WaterLevel.h"
#include "LCD.h"

bool debug = false;

Status currentStatus = NORMAL;
volatile bool manual = true; 
int valveOpening = 0;
double waterDistance;

Task* valve;

Task* waterLevel;
Task* lcd;

void setup() {
    Serial.begin(9600);
    valve = new Valve(A0, 6, 200);
    enableInterrupt(2, buttonInt, HIGH);

    waterLevel = new WaterLevel(7, 8, 1000, 13);
    lcd = new LCD(1000);
}

void loop() {
    waterLevel->tick();
    lcd->tick();
    delay(500);
}

