#ifndef __SIMPLE_SCHEDULER_H
#define __SIMPLE_SCHEDULER_H

#include "scheduler.hpp"

#define MAX_TASKS 10

class SimpleScheduler : public Scheduler {
public:
    void schedule();
    void addTask(Task* task);
private: 
    unsigned long period;
    Task* tasks[MAX_TASKS];
    unsigned int nTasks = 0;
    void computePeriod();
    unsigned long gcd(unsigned long a, unsigned long b);
};

#endif