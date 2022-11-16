#ifndef __SMARTLIGHT_H__
#define __SMARTLIGHT_H__
#include "Task.h"

class SmartLight : public Task
{
    private: 
        int La; 
        int Pir;
        int LS;
        int period;

    public:
        SmartLight(int La, int Pir, int LS, int period);
        void tick();
        void removeTask();
};

#endif