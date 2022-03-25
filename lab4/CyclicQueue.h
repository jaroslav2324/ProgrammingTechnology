#include <iostream>


template <typename T>
struct QueueElement{
    T element;
    T* ptrNext = nullptr;
};

template <typename T>
class CyclicQueue{
public:
    CyclicQueue();
    ~CyclicQueue();
    void addElementToBeginning();
    void addElementToEnd();
    void printQueue();
private:
    T* ptrFirst = nullptr;
    T* ptrLast = nullptr;
};

template <typename T>
void CyclicQueue<T>::addElementToBeginning(){

    if (ptrLast == nullptr){

    }

}

template <typename T>
void CyclicQueue<T>::addElementToEnd(){

    if (ptrFirst == nullptr){
        //T* newElement = new T;
        //newElement 
    }
}