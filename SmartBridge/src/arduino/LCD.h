#ifndef __LCD_H__
#define __LCD_H__
#include "Task.h"
#include "LiquidCrystal_I2C.h"


class LCD : public Task {
public:
    LCD(unsigned long period);
    void tick();

protected: 
    void toExecute();

private: 
    LiquidCrystal_I2C* lcd;
    bool isOn = false;
};

#endif