#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include <TimerOne.h>
#include "Task.h"
#define MAX_TASKS 10

class Scheduler{
    int basePeriod;
    int nTasks;
    Task* taskList[MAX_TASKS];
};

#endif