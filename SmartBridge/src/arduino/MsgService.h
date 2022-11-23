#ifndef __MSGSERVICEBT__
#define __MSGSERVICEBT__

#include "Arduino.h"
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
class MsgService {
    
public: 
    void init();  
    bool isMsgAvailable();
    Msg* receiveMsg();
    void sendMsg(Msg msg);

private:
    BSONObject content;
    Msg* availableMsg;
    String buffer = "";
    bool msgAvailable;
};

#endif