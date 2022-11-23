#include "Arduino.h"
#include "MsgServiceBT.h"

MsgServiceBT::MsgServiceBT(int rxPin, int txPin) {
    this->channel = new SoftwareSerial(rxPin, txPin);
}

void MsgServiceBT::init() {
    this->channel->begin(9600);
    availableMsg = NULL;
}

bool MsgServiceBT::sendMsg(Msg msg) {
    this->channel->write(msg.getContent().rawData());
    this->channel->write("\n");
}

bool MsgServiceBT::isMsgAvailable() {
    while (this->channel->available()) {
        char ch = this->channel->read();
        if (ch == '\n') {
            this->availableMsg = new Msg(BSONObject(this->stringToCArr(this->buffer)));
            this->buffer = "";
            return true;
        } else {
            this->buffer += ch;
        }
    }
    return false;
}

Msg* MsgServiceBT::receiveMsg() {
    if (this->availableMsg != NULL) {
        Msg* msg = availableMsg;
        this->availableMsg = NULL;
        return msg;
    } else {
        return NULL;
    }
}

char* MsgServiceBT::stringToCArr(String toConvert) {
    char p[toConvert.length()];
    for (int i = 0; i < sizeof(p); i++) {
        p[i] = toConvert[i];
    }
    return p;
}
