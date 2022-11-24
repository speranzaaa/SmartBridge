#ifndef __CONFIG_H__
#define __CONFIG_H__

#define WL_MAX 3.0  // Threshold for ALARM
#define WL_2 5.0    // Threshold for PRE_ALARM
#define POT_PIN A0

enum Status {
    NORMAL, 
    PRE_ALARM,
    ALARM
};

#endif