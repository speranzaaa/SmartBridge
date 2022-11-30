#include <Arduino.h>
#include "Config.h"
#include "Task.h"
#include "SerialTask.h"
#include "LCD.h"
#include "SimpleScheduler.hpp"
#include "WaterLevel.h"
#include "SmartLight.h"
#include "Valve.h"
#include "BlinkingLed.h"
#include "ButtonInterrupt.h"
#include "EnableInterrupt.h"

Status currentStatus = NORMAL;
volatile bool manual = false;
int valveOpening = 0;
bool isLightOn = false;
double waterDistance;

SimpleScheduler* scheduler;

Task* serialTask;
Task* lcdTask;
Task* waterLevelTask;
Task* smartLightTask;
Task* valveTask;
Task* blinkingLedTask;


void setup() {
    scheduler = new SimpleScheduler();

    enableInterrupt(2, buttonInt, RISING);

    serialTask = new SerialTask(2000);
    lcdTask = new LCD(1000);
    waterLevelTask = new WaterLevel(7, 8, 1000, 12);
    smartLightTask = new SmartLight(11, A1, 4, 500);
    valveTask = new Valve(A0, 6, 500);
    blinkingLedTask = new BlinkingLed(13, 1000);
    
    scheduler->addTask(serialTask);
    scheduler->addTask(lcdTask);
    scheduler->addTask(waterLevelTask);
    scheduler->addTask(smartLightTask);
    scheduler->addTask(valveTask);
    scheduler->addTask(blinkingLedTask);
}

void loop() {
    scheduler->schedule();
}

