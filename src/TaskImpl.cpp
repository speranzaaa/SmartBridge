#include "Task.h"

class TaskImpl : public Task
{
    public:
    void init(int period)
    {
        this->period = period;
    }
};