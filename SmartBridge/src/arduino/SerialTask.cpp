#include "SerialTask.h"
#include "Arduino.h"
#include "ArduinoJson.h"
#include "Config.h"

extern Status currentStatus;

SerialTask::SerialTask(unsigned long period) : Task(period) {
    this->service = new MsgService();
    this->service->init();
}

void SerialTask::toExecute() {
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
    this->service->sendMsg(&doc);
}