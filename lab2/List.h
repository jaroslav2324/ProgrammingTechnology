#pragma once
#include <iostream>

struct ListElement {
    double number;
    struct ListElement* ptrNext = nullptr;
};

class List {
    public:
    List();
    explicit List::List(unsigned int amount);
    ~List();
    void addElement();
    ListElement* popElement();
    friend void printList(List* q);

    List& operator++();
    List& operator++(int ignored);
    friend List& operator--(List& list);
    friend List& operator--(List& list, int ignored);

    private:
    struct ListElement* ptrFirstElement;
    struct ListElement* ptrLastElement;

};

void printList(List* q);