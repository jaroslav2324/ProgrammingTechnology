#include <iostream>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int enterUint(){

    int num;

    cout << "Enter usigned int number" << endl;
    cin >> num;

    while (!(cin.good()) || num < 0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong number! Try once again!" << endl; 
        cout << "Enter unsigned int number" << endl;
        cin >> num;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return num;
}

template <typename T>
class QueueElement{
    friend class CyclicQueue;
    T element;
    QueueElement<T>* ptrNext = nullptr;
};
/*
template<>
class QueueElement<char *>{
    friend class CyclicQueue;
    char* element;
    QueueElement<char *>* ptrNext = nullptr;
};
*/
template <typename T>
class CyclicQueue{
public:
    CyclicQueue();
    ~CyclicQueue();
    void printQueue();
    void queueMenu();
    CyclicQueue<T> operator+(QueueElement<T>* newElement);
    CyclicQueue<T> operator+(int ignored);
    CyclicQueue<T> operator-(int ignored);
    bool operator!();
private:
    QueueElement<T>* ptrFirst = nullptr;
    QueueElement<T>* ptrLast = nullptr;
    int amountElements = 0;
    void enterValue();
    friend int enterUint();
    T createRandomValue();
    char* createStringRandomLength();
};

template <typename T>
CyclicQueue<T>::CyclicQueue(){

    cout << "Enter size of queue: " << endl;
    int num = enterUint();

    QueueElement<T> newElement;

    for (int i = 0; i < num; i++){
        newElement = new QueueElement<T>;
        newElement->element = createRandomValue();
        *this + newElement;
    }

}

template <>
CyclicQueue<char*>::CyclicQueue(){

    cout << "Enter size of queue: " << endl;
    int num = enterUint();

    QueueElement<char*>* newElement;

    for (int i = 0; i < num; i++){
        newElement = new QueueElement<char*>;
        newElement->element = createStringRandomLength();
        *this + newElement;
    }
}

template <typename T>
CyclicQueue<T>::~CyclicQueue(){

    QueueElement<T>* delElement = ptrFirst,* buffElement;

    while (delElement != ptrLast){
        buffElement = delElement->ptrNext;
        delete delElement;
        delElement = buffElement;
    }

    delete ptrLast;
}

template <>
CyclicQueue<char *>::~CyclicQueue(){

    QueueElement<char *>* delElement = ptrFirst,* buffElement;

    while (delElement != ptrLast){
        buffElement = delElement->ptrNext;
        delete[] delElement->element;
        delete delElement;
        delElement = buffElement;
    }

    delete[] ptrLast->element;
    delete ptrLast;
}

template <typename T>
void CyclicQueue<T>::enterValue(){

    T value;

    cout << "Enter value" << endl;
    cin >> value;

    while (!(cin.good())){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong value! Try once again!" << endl; 
        cout << "Enter value" << endl;
        cin >> value;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return value;

}

template <typename T>
T CyclicQueue<T>::createRandomValue(){

    return rand() % 51; 
}

template<typename T>
char* CyclicQueue<T>::createStringRandomLength(){

    int len = -1;

    while(len < 2)
    len = rand() % 51;
    
    char string = new char[len];
    string[len - 1] = '\n';

    char asciiSymbol = -1;
    for (int i = 0; i < len - 1, i++){
        asciiSymbol = -1;
        while (asciiSymbol < 32 || asciiSymbol > 126)
            asciiSymbol = rand() % 51;
        string[i] = asciiSymbol;
    }
}

template <typename T>
void CyclicQueue<T>::queueMenu(){

    while(1){
        cout << "1 - add element to queue" << endl << "2 - delete element from queue" << "3 - check if queue is empty" << "4 - print queue"<< endl 
        << "b - go back" << endl;
        char c = getch();
        switch(c){
            case '1':
                *this + 0;
                break;
            case '2':
                *this - 0;
                break;
            case '3':
                cout << !(*this) << endl;
                break;
            case '4':
                printQueue();
                break;
            case 'b':
                return;
            default:
                cout << "Wrong key" << endl;
        }
    }
}

template <typename T>
CyclicQueue<T> CyclicQueue<T>::operator+(int ignored){

    QueueElement<T>* newElement = new QueueElement<T>;
    newElement->element = enterValue();

    if (ptrFirst == nullptr){

        newElement->ptrNext = newElement;

        ptrFirst = newElement;
        ptrLast = newElement;

        cout << "Added" << endl;
        amountElements++;
        return *this;
    }

    if (ptrFirst == ptrLast){

        newElement->ptrNext = ptrFirst;
        ptrFirst->ptrNext = newElement;

        ptrLast = newElement;

        cout << "Added" << endl;
        amountElements++;
        return *this;
    }

    newElement->ptrNext = ptrFirst;
    ptrLast->ptrNext = newElement;
    ptrLast = newElement;
    amountElements++;

    cout << "Added" << endl;
    return *this;
}

template <typename T>
CyclicQueue<T> CyclicQueue<T>::operator+(QueueElement<T>* newElement){

    if (ptrFirst == nullptr){

        newElement->ptrNext = newElement;

        ptrFirst = newElement;
        ptrLast = newElement;

        amountElements++;
        return *this;
    }

    if (ptrFirst == ptrLast){

        newElement->ptrNext = ptrFirst;
        ptrFirst->ptrNext = newElement;

        ptrLast = newElement;

        amountElements++;
        return *this;
    }

    newElement->ptrNext = ptrLast;
    ptrFirst->ptrNext = newElement;
    ptrLast = newElement;
    amountElements++;
    return *this;

}

template <typename T>
CyclicQueue<T> CyclicQueue<T>::operator-(int ignored){

    if (ptrFirst == nullptr){

        cout << "Nothing to delete!" << endl;
        return *this;
    }

    if (ptrFirst == ptrLast){

        delete ptrFirst;
        amountElements--;

        ptrFirst = nullptr;
        ptrLast = nullptr;

        cout << "Deleted" << endl;
        return *this;
    }

    QueueElement<T>* delElement = ptrFirst;
    ptrFirst = ptrFirst->ptrNext;
    ptrLast->ptrNext = ptrFirst;
    amountElements--;

    delete delElement;
    return *this;
}

/*if queue is empty, returns 1 either 0*/
template <typename T>
bool CyclicQueue<T>::operator!(){

    return amountElements == 0 
}
