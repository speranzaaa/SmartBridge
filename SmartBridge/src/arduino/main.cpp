#include <Arduino.h>
#include "Config.h"
#include "MsgService.h"
#include "ArduinoJson.h"
#include "Valve.h"
#include "Task.h"

bool debug = false;

Status currentStatus = ALARM;
bool manual = true; 
double waterDistance;

Task* valve;

void setup() {
    Serial.begin(9600);
    valve = new Valve(A0, 6, 100);
}

void loop() {
    valve->tick();
    delay(50);
}
