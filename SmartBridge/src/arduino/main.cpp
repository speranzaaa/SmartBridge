#include <Arduino.h>
#include "Config.h"
#include "MsgService.h"
#include "ArduinoJson.h"
bool debug = false;

Status currentStatus = NORMAL;
bool manual = false; 
double waterDistance;
MsgService service;

void setup() {
    service.init();
}

void loop() {

}
