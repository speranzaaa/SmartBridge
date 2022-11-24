#include "simpleScheduler.hpp"

void SimpleScheduler::schedule() {

}

void SimpleScheduler::addTask(Task* task) {
    this->nTasks++;
    if(nTasks == 1) {
        tasks[0] = task;
        this->period = task->getPeriod(); 
    } else {
        tasks[nTasks-1] = task;
        this->period = gcd(this->period, task->getPeriod());
    }
}

unsigned long SimpleScheduler::gcd(unsigned long a, unsigned long b){
    return b == 0 ? a :gcd(b, a%b);
}
