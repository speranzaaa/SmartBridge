#ifndef __SONAR_H__
#define __SONAR_H__

#include "sensor.hpp"

class Sonar
{
private:
    // The speed of sound, assuming the current temp is 20C
    const double SOUNDSPEED = 331.45 + 0.62 * 20;
    unsigned int trigPin;
    unsigned int echoPin;
public:
    /**
     * @brief Construct a new Sonar object
     * 
     * @param trigPin the number of the trig pin
     * @param echopin the number of the echo pin
     */
    Sonar(unsigned int trigPin, unsigned int echopin);
    ~Sonar();
    /**
     * @brief Get the distance
     * 
     * @return double the distance in meters
     */
    double getDistance();
};



#endif