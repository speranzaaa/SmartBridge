#ifndef __SMARTLIGHT_H__
#define __SMARTLIGHT_H__
#include "TaskImpl.cpp"

class SmartLight : public TaskImpl
{
    private: 
        int La; 
        int Pir;
        int LS;

    public:
        SmartLight(int La, int Pir, int LS, int period);
};

#endif