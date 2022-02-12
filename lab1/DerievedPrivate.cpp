#include "DerievedPrivate.h"

DerPrivate::DerPrivate(){
    ptrFirstElement = nullptr;
    ptrLastElement = nullptr;
}

//free memory
DerPrivate::~DerPrivate(){
    struct QueueElement* element = ptrFirstElement->ptrNext;
    while(ptrFirstElement){
        delete(ptrFirstElement);
        ptrFirstElement = element;
        if (ptrFirstElement)
            element = ptrFirstElement->ptrNext;
    }
    return;
}