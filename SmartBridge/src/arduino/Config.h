#ifndef __CONFIG_H__
#define __CONFIG_H__

#define WL_MAX 0.3  // Threshold for ALARM
#define WL_2 0.5    // Threshold for PRE_ALARM
#define POT_PIN A0
#define PE_NORMAL 1000
#define PE_PREALARM 700
#define PE_ALARM 400

enum Status {
    NORMAL, 
    PRE_ALARM,
    ALARM
};

#endif