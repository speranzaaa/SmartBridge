#ifndef LED
#define LED

#include "Light.h"

class Led : public Light {
public:
    Led(int pin);
    Led();
    bool isOn();
    void turnOn();
    void turnOff();
    void setPin(int pin);
private:
    int pin;
    bool powered;
};

#endif