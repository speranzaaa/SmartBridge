#ifndef __BUTTON_INTERRUPT__
#define __BUTTON_INTERRUPT__

#include <Arduino.h>
extern volatile bool manual;

void buttonInt() {
    static unsigned long lastInt = 0;
    unsigned long currTime = millis();
    if (currTime - lastInt > 200){
        manual = manual == false ? true : false;
        lastInt = currTime;
    }
}

#endif