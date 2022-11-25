#include "TaskRunner.hpp"

void TaskRunner::consume(Task* task) {
    if (task->getPeriod()==0){
            task->tick();
        }
}