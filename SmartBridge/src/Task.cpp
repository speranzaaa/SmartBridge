#include "Task.h"

void Task::init(unsigned long period) {
    this->period = period;
}

unsigned long Task::getPeriod() {
    return this->period;
}