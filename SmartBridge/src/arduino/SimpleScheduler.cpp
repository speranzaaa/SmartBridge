#include "simpleScheduler.hpp"

SimpleScheduler::SimpleScheduler() {
    this->taskList = new LinkedTaskList();
}

void SimpleScheduler::schedule() {

}

void SimpleScheduler::addTask(Task* task) {
    this->taskList->addTask(task);
    if(taskList->getSize() == 1) {
        this->period = task->getPeriod(); 
    } else {
        this->period = gcd(this->period, task->getPeriod());
    }
}

unsigned long SimpleScheduler::gcd(unsigned long a, unsigned long b){
    return b == 0 ? a :gcd(b, a%b);
}
