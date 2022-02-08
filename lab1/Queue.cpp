#define NULL 0
#include <iostream>

struct QueueElement {
    char name[50];
    struct QueueElement* ptrNext = NULL;
};

class Queue {
    public:
    Queue();
    ~Queue();
    void addElement();
    void deleteElement();
    class Queue* copyQueue();
    class Queue* mergeQueues(class Queue* ptrFirstQueue, class Queue* ptrLastQueue);
    private:
    struct QueueElement* ptrFirstElement;
    struct QueueElement* ptrLastElement;
    protected:
};

Queue::Queue(){
    ptrFirstElement = NULL;
    ptrLastElement = NULL;
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
    std::cout << "Enter name:" << std::endl;
    std::cin >> element->name;

    if (ptrFirstElement == NULL){
        ptrFirstElement = element;
        ptrLastElement = element;
        return;
    }

    ptrLastElement->ptrNext = element;
    ptrLastElement = element;
    return;
}

void Queue::deleteElement(){
    if (ptrFirstElement == NULL){
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
    /* rework is needed, not complited*/
        if (element == ptrFirstElement)
            newQueue->ptrFirstElement = elementInNewQueue;
        if (element == ptrLastElement)
            newQueue->ptrLastElement = elementInNewQueue;

        previousElementInNewQueue = elementInNewQueue;
        element = element->ptrNext;
        //
    }
    //
    return NULL;
}

    class Queue* Queue::mergeQueues(class Queue* ptrFirstQueue, class Queue* ptrLastQueue){

 //
    return NULL;
    }