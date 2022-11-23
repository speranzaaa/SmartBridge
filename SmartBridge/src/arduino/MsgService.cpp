#include "Arduino.h"
#include "MsgService.h"
#include "ArduinoJson.h"

void MsgService::init() {
    Serial.begin(9600);
    Serial.setTimeout(1);
}

void MsgService::sendMsg(DynamicJsonDocument* msg) {
    serializeJson(*msg, Serial);
    Serial.print('\n');
}
