#include <random>

#include "List.h"

/*unsigned int from 1 to max unsigned int size*/
List::List(){

    unsigned int amount;
    std::cout << "Enter length of list" << std::endl;
    std::cin >> amount;
    if (!(std::cin.good())){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong length of list! Initialising empty list..." << std::endl << std::endl; 
        amount = 0;
    }

    if (amount == 0){
        ptrFirstElement = nullptr;
        ptrLastElement = nullptr;
        return;
    }

    for (uint i = 0; i < amount; i++){
        struct ListElement* newElement = new struct ListElement;
        struct ListElement* previousElement;


        newElement->number = randNumInRange_10_20();

        if (i == 0){
            ptrFirstElement = newElement;
            previousElement = newElement;
            continue;
        }
        else if (i == amount - 1){
            ptrLastElement = newElement;
        }

        previousElement->ptrNext = newElement;
        previousElement = newElement;
    }
    return;
}

//free memory
List::~List(){
    if (!ptrFirstElement)
        return;
    struct ListElement* element = ptrFirstElement->ptrNext;
    while(ptrFirstElement){
        delete(ptrFirstElement);
        ptrFirstElement = element;
        if (ptrFirstElement)
            element = ptrFirstElement->ptrNext;
    }
    return;
}

void List::addElement(){
    struct ListElement* element = new struct ListElement;
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

struct ListElement* List::popElement(){
    if (ptrFirstElement == nullptr){
        std::cout << "Nothing to delete!" << std::endl;
        return nullptr;
    }

    struct ListElement* popElem = ptrFirstElement;
    ptrFirstElement = ptrFirstElement->ptrNext;
    
    return popElem;
}


void printList(List* l){
    ListElement* element = l->ptrFirstElement;

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

List& List::operator++(){

    ListElement* newElem = new ListElement;
    newElem->number = randNumInRange_10_20();

    if (ptrFirstElement == nullptr){
        ptrFirstElement = newElem;
        ptrLastElement = newElem;
        return *this;
    }

    newElem->ptrNext = ptrFirstElement;
    ptrFirstElement = newElem;
    return *this;

}

List& List::operator++(int ignored){

    ListElement* newElem = new ListElement;
    newElem->number = randNumInRange_10_20();

    if (ptrFirstElement == nullptr){
        ptrFirstElement = newElem;
        ptrLastElement = newElem;
        return *this;
    }

    ptrLastElement->ptrNext = newElem;
    ptrLastElement = newElem;
    return *this;
}

List& operator--(List& list){

    if (list.ptrFirstElement == nullptr){
        std::cout << "Nothing to delete" << std::endl;
        return list;
    }

    if (list.ptrFirstElement == list.ptrLastElement){
        delete(list.ptrFirstElement);
        list.ptrFirstElement = nullptr;
        list.ptrLastElement = nullptr;
        return list;
    }

    ListElement* delElem = list.ptrFirstElement;
    list.ptrFirstElement = list.ptrFirstElement->ptrNext;
    delete(delElem);

    return list;
}

List& operator--(List& list, int ignored){

    if (list.ptrFirstElement == nullptr){
       std::cout << "Nothing to delete" << std::endl;
       return list;
    }

    if (list.ptrFirstElement == list.ptrLastElement){
        delete(list.ptrFirstElement);
        list.ptrFirstElement = nullptr;
        list.ptrLastElement = nullptr;
        return list;
    }

    ListElement* delElem = list.ptrFirstElement;

    while(delElem->ptrNext != list.ptrLastElement)
        delElem = delElem->ptrNext;
    
    delete(list.ptrLastElement);
    list.ptrLastElement = delElem;
    list.ptrLastElement->ptrNext = nullptr;

    return list;

}

unsigned int List::randNumInRange_10_20(){

    uint num = std::rand() % 21;
    if (num < 10)
        num += 10;
    return num;
}
/*enter unsigned int*/
int enterint(){

    int num;

    std::cout << "Enter int number" << std::endl;
    std::cin >> num;

    while (!(std::cin.good())){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong number! Try once again!" << std::endl; 
            std::cout << "Enter unsigned int number" << std::endl;
        std::cin >> num;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return num;
}
