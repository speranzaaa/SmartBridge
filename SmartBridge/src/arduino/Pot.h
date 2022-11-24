#ifndef __POT_H__
#define __POT_H__

#include <Arduino.h>

/**
 * @brief Sensor class describing a potentiometer
 */
class Pot {
public:
    /**
     * @brief Get the value the the value should
     * be opened at 
     * 
     * @return int the value the valve should be
     * opened at, in degrees from 0 to 180
     */
    int getValveValue();
};

#endif