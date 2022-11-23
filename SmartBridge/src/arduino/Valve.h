#ifndef __VALVE_H__
#define __VALVE_H__

#include "Task.h"
#include "ServoMotorImpl.h"

class Valve : public Task {
public:
    Valve(int potPin, int servoPin, unsigned long period);
    void tick();

protected:
    void toExecute();

private:
    int potPin;
    int servoPin;
    int pos;   
    int delta;
    ServoMotor* servo;
};

#endif
