#ifndef __WATER_LEVEL_H__
#define __WATER_LEVEL_H__
#include "Task.h"
#include "sonar.hpp"

class WaterLevel : public Task {
public:
    WaterLevel(int trigPin, int echoPin, unsigned long period);
    void tick();

private:
    Sonar* sonar;
    unsigned long elapsedTime = 0;
};

#endif