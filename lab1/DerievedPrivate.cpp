#include "DerievedPrivate.h"

DerPrivate::DerPrivate(){

}

DerPrivate::~DerPrivate(){

}

void DerPrivate::countElementsMoreAverage(){
    int count = 0;
    float denominator = 0;

    QueueElement* element = returnPtrFirst();
    if (!element){
        std::cout << "Nothing to count!";
        return;
    }

    while(element){
        denominator += (float)1 / (float)element->number;
        count += 1;
        element = element->ptrNext;
    }

    float average = count / denominator;

    element = returnPtrFirst();
    count = 0;

    while(element){
        if (element->number > average)
            count += 1;
        element = element->ptrNext;
    }

    std::cout << "Values more than average garmonic " << count << std::endl;

    return;
}