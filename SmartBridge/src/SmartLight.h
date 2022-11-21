#ifndef __SMARTLIGHT_H__
#define __SMARTLIGHT_H__
#include "Task.h"
#include "pir.hpp"
#include "led.h"
#include "lightSensor.h"

class SmartLight : public Task
{
    private: 
        /**
         * @brief The SmartBrigde light.
         */
        Led* bridgeLight; 
        /**
         * @brief The SmartBrigde movement sensor.
         */
        Pir* pir;
        LightSensor* lightSensor;
        unsigned long timeDetected = 0;
        unsigned long elapsedTime = 0;

    public:
        /**
         * @brief Construct a new Smart Light object
         * 
         * @param lightPin the pin used by the SmartBrigde light
         * @param lightSensorPin the pin used by the light sensor
         * @param pirPin the pin used by the movement sensor
         * @param period the period of the task
         */
        SmartLight(int lightPin, int lightSensorPin, int pirPin, int period);
        void tick();
};

#endif