#include <Arduino.h>
#include "Config.h"
#include "MsgService.h"
#include "ArduinoJson.h"
bool debug = false;

Status currentStatus = NORMAL;
MsgService service;

void setup() {
    service.init();
}

void loop() {
    String status;
    switch (currentStatus) {
    case NORMAL:
        status = "normal";
        break;
    case PRE_ALARM:
        status = "pre-alarm";
        break;
    default:
        status = "alarm";
        break;
    }
    String light = currentStatus == ALARM ? "OFF" : "ON";
    DynamicJsonDocument doc(1024);
    doc["status"] = status;
    doc["light"] = light;
    service.sendMsg(&doc);
    randomSeed(analogRead(A0));
    int rNum = rand() % 3;
    switch (rNum)
    {
    case 0:
        currentStatus = NORMAL;
        break;

    case 1:
        currentStatus = PRE_ALARM;
        break;
    
    default:
        currentStatus = ALARM;
        break;
    }
    delay(1000);
}
