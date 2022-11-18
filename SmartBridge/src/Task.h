#ifndef __TASK__
#define __TASK__

class Task
{
    public:
        virtual void tick() = 0;
        virtual void removeTask() = 0;
    protected:
        void init(int period);
    private:
        int period;
};

#endif 