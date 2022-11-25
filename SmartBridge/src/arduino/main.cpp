#include <Arduino.h>
#include "Config.h"
#include "MsgService.h"
#include "Valve.h"
#include "Task.h"
#include "EnableInterrupt.h"
#include "ButtonInterrupt.h"
#include "ButtonInterrupt.h"
#include "WaterLevel.h"
#include "LCD.h"

bool debug = false;
Servo servo;

Status currentStatus = NORMAL;
volatile bool manual = false;
int valveOpening = 0;
double waterDistance;

Task* valve;
Task* waterLevel;
Task* lcd;

void setup() {
    Serial.begin(9600);
    valve = new Valve(A0, 11, 500);
    waterLevel = new WaterLevel(7, 8, 1000, 13);
    enableInterrupt(2, buttonInt, HIGH);
    lcd = new LCD(1000);
}

void loop() {
    waterLevel->tick();
    lcd->tick();
    valve->tick();
    delay(500);
}

