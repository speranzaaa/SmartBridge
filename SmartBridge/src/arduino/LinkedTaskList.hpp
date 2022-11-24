#ifndef LINKED_TASK_LIST_H
#define LINKED_TASK_LIST_H

#include "TaskList.hpp"

class LinkedTaskList : public TaskList {
public:
    LinkedTaskList(); 
    bool isEmpty();
    int getSize();
    void addTask(Task* task);

private:
    struct Node {
        Task* task;
        Node* next;
    };
    Node* first = NULL;
    Node* last = NULL;
};

#endif