#include "DerievedPublic.h"

DerPublic::DerPublic(){
    ptrFirstElement = nullptr;
    ptrLastElement = nullptr;
}

//free memory
DerPublic::~DerPublic(){
    struct QueueElement* element = ptrFirstElement->ptrNext;
    while(ptrFirstElement){
        delete(ptrFirstElement);
        ptrFirstElement = element;
        if (ptrFirstElement)
            element = ptrFirstElement->ptrNext;
    }
    return;
}

void DerPublic::countElementsMoreAverage(){
    int count;
    float denominator;

    
}