#include "SimpleScheduler.hpp"

void SimpleScheduler::schedule() {

}

void SimpleScheduler::addTask(Task* task) {
    if(nTasks == 0) {
        tasks[0] = task;
        this->nTasks++;
        this->period = task->getPeriod(); 
    }
}

void SimpleScheduler::computePeriod() {
    if(nTasks == 1) {
        this->period = tasks[0]->getPeriod();
    } else if (nTasks > 1) {
        
        for(int i = 0; i<nTasks; i++);
    }
}

unsigned long SimpleScheduler::gcd(unsigned long a, unsigned long b){
    return b == 0 ? a :gcd(b, a%b);
}
