#ifndef __MSGSERVICEBT__
#define __MSGSERVICEBT__

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "ardubson.h"

class Msg {
    BSONObject content;

public:
    Msg(const BSONObject content){
        this->content = content;
    }
    
    BSONObject getContent(){
        return content;
    }
    };

/**
 * @brief Class used to send and receive messages over serial
 * using BSONObjects
 */
class MsgServiceBT {
    
public: 
    MsgServiceBT(int rxPin, int txPin);  
    void init();  
    bool isMsgAvailable();
    Msg* receiveMsg();
    bool sendMsg(Msg msg);

private:
    BSONObject content;
    Msg* availableMsg;
    SoftwareSerial* channel;
    String buffer;
  
};

#endif