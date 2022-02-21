#include <iostream>
#include "Queue.h"

Queue::Queue(){
    ptrFirstElement = nullptr;
    ptrLastElement = nullptr;
}

//free memory
Queue::~Queue(){
    if (!ptrFirstElement)
        return;
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
    std::cout << element->number << " added" << std::endl;
    if (!std::cin){
        std::cout << std::endl << "It is not a number!" << std::endl;
        delete(element);
         std::cin.clear();
        std::cin.ignore(1000000, '\n');
        return;
    }

    std::cin.ignore(1000000, '\n');

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

struct QueueElement* Queue::returnPtrFirst(){
    return ptrFirstElement;
}

class Queue* mergeQueues(Queue* q1, Queue* q2){

    class Queue* newQueue = new class Queue;

    struct QueueElement* elementInNewQueue; 
    struct QueueElement* previousElementInNewQueue = nullptr; // to add ptrNext to the element

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

    element = q2->ptrFirstElement; 

    while(element){
        elementInNewQueue = new struct QueueElement;
        elementInNewQueue->number = element->number;

        if (element == q2->ptrFirstElement && !previousElementInNewQueue){
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

    return newQueue;
}

void printQueue(Queue* q){
    QueueElement* element = q->ptrFirstElement;

    if (element == nullptr){
        std::cout << "Nothing to print!" << std::endl;
        return;
    }

    while(element->ptrNext){
        std::cout << element->number << "<-";
        element = element->ptrNext;
    }
    std::cout << element->number << std::endl;
    return;
}
