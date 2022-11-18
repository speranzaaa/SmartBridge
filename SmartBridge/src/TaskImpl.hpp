#ifndef __TASKIMPL_H__
#define __TASKIMPL_H__

class TaskImlp : public Task {
public:
    @override
    virtual void tick() = 0;
    @override
    virtual void removeTask() = 0;
private:
    int period;

protected:
    void init(int perdiod);

}

#endif