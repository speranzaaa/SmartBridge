#include "Arduino.h"
#include "MsgService.h"

void MsgService::init() {
    Serial.begin(9600);
    Serial.setTimeout(1);
    this->availableMsg = NULL;
    this->content = NULL;
}

void MsgService::sendMsg(Msg msg) {
    Serial.println(msg.getContent().jsonString());
}

bool MsgService::isMsgAvailable() {
    while (Serial.available()) {
        char ch = Serial.read();
        if (ch == '\n') {
            char p[this->buffer.length()];
            for (unsigned int i = 0; i < sizeof(p); i++) {
                p[i] = this->buffer[i];
            }
            this->availableMsg = new Msg(BSONObject(p));
            this->buffer = "";
            return true;
        } else {
            this->buffer += ch;
        }
    }
    return false;
}

Msg* MsgService::receiveMsg() {
    if (this->availableMsg != NULL) {
        Msg* msg = availableMsg;
        this->availableMsg = NULL;
        return msg;
    } else {
        return NULL;
    }
}
