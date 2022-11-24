#ifndef __POT_H__
#define __POT_H__

#include "Sensor.hpp"

/**
 * @brief Sensor class describing a potentiometer
 */
class Pot : public Sensor {
public:
    /**
     * @brief Construct a new Pot object
     * 
     * @param potPin the pin of the potentiometer
     */
    Pot(int potPin);
    /**
     * @brief Get the value the the value should
     * be opened at 
     * 
     * @return int the value the valve should be
     * opened at, in degrees from 0 to 180
     */
    int getValveValue();

private:
    int pin;
};

#endif