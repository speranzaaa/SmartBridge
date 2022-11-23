#include <Arduino.h>
#include "Config.h"
#include "MsgService.h"
#include "ardubson.h"
bool debug = false;

Status currentStatus = NORMAL;
MsgService service;

void setup() {
    service.init();
}

void loop() {
    BSONObjBuilder builder;
    builder.append("hello", "world");
    BSONObject msg = builder.obj();
    service.sendMsg(msg);
    delay(1000);
}
