#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "task.h"

class Scheduler {
public:
    virtual void schedule() = 0;
    virtual void addTask(Task* task) = 0;
};

#endif
