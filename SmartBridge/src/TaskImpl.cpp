#include "Task.h"

class TaskImpl : public Task
{
    protected:
    void init(int period)
    {
        this->period = period;
    }
};