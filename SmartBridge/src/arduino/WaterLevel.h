#ifndef __WATER_LEVEL_H__
#define __WATER_LEVEL_H__
#include "Task.h"
#include "Sonar.hpp"
#include "Led.h"

class WaterLevel : public Task {
public:
    WaterLevel(int trigPin, int echoPin, unsigned long period, int ledPin);
    void tick();

protected:
    void toExecute();

private:
    Sonar* sonar;
    Led* led;
    unsigned long elapsedTime = 0;
};

#endif