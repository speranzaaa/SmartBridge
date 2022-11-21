#ifndef __BLINKING_LED_H__
#define __BLINKING_LED_H__
#include "Task.h"
#include "led.h"

/**
 * @brief Task class implementation for the red
 * blinking led. Blinks with a period of 2' on PRE_ALARM
 * state and is always on during ALARM state.
 * 
 */
class BlinkingLed : public Task {

public:
    /**
     * @brief Construct a new Blinking Led object
     * 
     * @param period the period with which the task should be ran.
     * @param ledPin the pin number of the led the task will use.
     */
    BlinkingLed(unsigned long period, int ledPin);
    void tick();

private:
    Led led;
    unsigned long lastActionTime = 0;

};

#endif