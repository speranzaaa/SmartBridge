#ifndef __VALVE_H__
#define __VALVE_H__

#include "Task.h"
#include "ServoMotorImpl.h"
#include "Pot.h"

class Valve : public Task {
public:
    Valve(int potPin, int servoPin, unsigned long period);
    void tick();

protected:
    void toExecute();

private:
    int servoPin;
    int pos;   
    int delta;
    ServoMotor* servo;
    Pot* pot;
};

#endif
