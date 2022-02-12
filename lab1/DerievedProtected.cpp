#include "DerievedProtected.h"

DerProtected::DerProtected(){
    ptrFirstElement = nullptr;
    ptrLastElement = nullptr;
}

//free memory
DerProtected::~DerProtected(){
    struct QueueElement* element = ptrFirstElement->ptrNext;
    while(ptrFirstElement){
        delete(ptrFirstElement);
        ptrFirstElement = element;
        if (ptrFirstElement)
            element = ptrFirstElement->ptrNext;
    }
    return;
}