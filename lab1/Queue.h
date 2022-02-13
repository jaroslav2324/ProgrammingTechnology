#pragma once
#include <iostream>

struct QueueElement {
    int number;
    struct QueueElement* ptrNext = nullptr;
};

class Queue {
    public:
    Queue();
    ~Queue();
    void addElement();
    void deleteElement();
    class Queue* copyQueue();
    friend void printQueue(Queue* q);
    friend class Queue* mergeQueues(Queue* q1, Queue* q2);
    private:
    struct QueueElement* ptrFirstElement;
    struct QueueElement* ptrLastElement;
    protected:
    struct QueueElement* returnPtrFirst();
};

class Queue* mergeQueues(Queue* q1, Queue* q2);
void printQueue(Queue* q);