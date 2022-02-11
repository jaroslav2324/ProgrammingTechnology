#include <iostream>
#include "Queue.h"

Queue::Queue(){
    ptrFirstElement = nullptr;
    ptrLastElement = nullptr;
}

//free memory
Queue::~Queue(){
    struct QueueElement* element = ptrFirstElement->ptrNext;
    while(ptrFirstElement){
        delete(ptrFirstElement);
        ptrFirstElement = element;
        if (ptrFirstElement)
            element = ptrFirstElement->ptrNext;
    }
    return;
}

void Queue::addElement(){
    struct QueueElement* element = new struct QueueElement;
    std::cout << "Enter number:" << std::endl;
    std::cin >> element->number;

    if (ptrFirstElement == nullptr){
        ptrFirstElement = element;
        ptrLastElement = element;
        return;
    }

    ptrLastElement->ptrNext = element;
    ptrLastElement = element;
    return;
}

void Queue::deleteElement(){
    if (ptrFirstElement == nullptr){
        std::cout << "Nothing to delete!" << std::endl;
        return;
    }

    struct QueueElement* delElem = ptrFirstElement;
    ptrFirstElement = ptrFirstElement->ptrNext;
    delete(delElem);
    return;
}

class Queue* Queue::copyQueue(){
    class Queue* newQueue = new class Queue;

    struct QueueElement* element = ptrFirstElement; //element in queue
    struct QueueElement* elementInNewQueue; 
    struct QueueElement* previousElementInNewQueue; // to add ptrNext to the element
    while(element){
        elementInNewQueue = new struct QueueElement;
        elementInNewQueue->number = element->number;

        if (element == ptrFirstElement){
            previousElementInNewQueue = elementInNewQueue;
            newQueue->ptrFirstElement = elementInNewQueue;
            element = element->ptrNext;
            continue;
        }
        previousElementInNewQueue->ptrNext = elementInNewQueue;
        previousElementInNewQueue = elementInNewQueue;
        element = element->ptrNext;
    }
    newQueue->ptrLastElement = elementInNewQueue;
    //
    return newQueue;
}

class Queue* mergeQueues(Queue* q1, Queue* q2){

    class Queue* newQueue = new class Queue;

    struct QueueElement* elementInNewQueue; 
    struct QueueElement* previousElementInNewQueue; // to add ptrNext to the element

    struct QueueElement* element = q1->ptrFirstElement; 

    while(element){
        elementInNewQueue = new struct QueueElement;
        elementInNewQueue->number = element->number;

        if (element == q1->ptrFirstElement){
            previousElementInNewQueue = elementInNewQueue;
            newQueue->ptrFirstElement = elementInNewQueue;
            element = element->ptrNext;
            continue;
        }
        previousElementInNewQueue->ptrNext = elementInNewQueue;
        previousElementInNewQueue = elementInNewQueue;
        element = element->ptrNext;
    }

    struct QueueElement* element = q2->ptrFirstElement; 

    while(element){
        elementInNewQueue = new struct QueueElement;
        elementInNewQueue->number = element->number;

        previousElementInNewQueue->ptrNext = elementInNewQueue;
        previousElementInNewQueue = elementInNewQueue;
        element = element->ptrNext;
    }
    newQueue->ptrLastElement = elementInNewQueue;

    return newQueue;
}
