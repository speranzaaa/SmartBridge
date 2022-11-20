#ifndef __TASK__
#define __TASK__

class Task
{
    public:
        virtual void tick() = 0;
        unsigned long getPeriod();
    protected:
        void init(unsigned long period);
    private:
        unsigned long period;
};

#endif 