#include <Arduino.h>
#include "Config.h"
#include "SerialTask.h"
#include "Task.h"
#include "LCD.h"

bool debug = false;

Status currentStatus = NORMAL;
volatile bool manual = false;
int valveOpening = 0;
bool isLigthOn = false;
double waterDistance;

Task* serialTask;

void setup() {
    serialTask = new SerialTask(1000);
}

void loop() {
    randomSeed(analogRead(A0));
    waterDistance = random() % 150;
    serialTask->tick();
    delay(500);
}

