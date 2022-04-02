#include <iostream>
#include <string>
#include <cstring>
#include <random>
#include <exception>

using std::cout;
using std::cin;
using std::endl;
using std::string;
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
class CyclicQueue;



template <typename T>
class QueueElement{
    T element;
    QueueElement<T>* ptrNext = nullptr;
    friend class CyclicQueue<T>;
};



template <typename T>
class CyclicQueue{
public:
    CyclicQueue();
    ~CyclicQueue();
    void printQueue();
    void queueMenu();
    void operator+(QueueElement<T>* newElement);
    void operator+(int ignored);
    void operator-(int ignored);
    bool operator!();
private:
    QueueElement<T>* ptrFirst = nullptr;
    QueueElement<T>* ptrLast = nullptr;
    int amountElements = 0;
    T enterValue();
    char* enterString();
    friend int enterUint();
    T createRandomValue();
    char* createStringRandomLength();
};

template <typename T>
CyclicQueue<T>::~CyclicQueue(){
    cout << "destructor working" << endl;
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
CyclicQueue<T>::CyclicQueue(){

    cout << "Enter size of queue: " << endl;
    int num = enterUint();

    QueueElement<T>* newElement;

    for (int i = 0; i < num; i++){
        newElement = new QueueElement<T>;
        newElement->element = createRandomValue();
        operator+(newElement);
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
void CyclicQueue<T>::printQueue(){

    if (amountElements == 0)
        return;

    QueueElement<T>* element = ptrFirst;

    while (element != ptrLast){
        cout << element->element << "<-";
        element = element->ptrNext;
    }
    
    cout << ptrLast->element;
}

template <>
void CyclicQueue<char *>::printQueue(){

    if (amountElements == 0)
        return;

    QueueElement<char*>* element = ptrFirst;

    while (element != ptrLast){
        cout << element->element;
        element = element->ptrNext;
    }
    
    cout << ptrLast->element;
}

template <typename T>
T CyclicQueue<T>::enterValue(){

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
char* CyclicQueue<T>::enterString(){

    string str;

    cout << "Enter string" << endl;
    cin >> str;

    while (!(cin.good())){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong string! Try once again!" << endl; 
        cout << "Enter string" << endl;
        cin >> str;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char* s = new char[str.length() + 2];
    strcpy(s, str.c_str());

    return s;

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
    
    char* string = new char[len];
    string[len - 1] = '\n';

    char asciiSymbol = -1;
    for (int i = 0; i < len - 1; i++){
        asciiSymbol = -1;
        while (asciiSymbol < 48 || (asciiSymbol > 57 && asciiSymbol < 65) || (asciiSymbol > 90 && asciiSymbol < 97) || asciiSymbol > 122)
            asciiSymbol = rand() % 256;
        string[i] = asciiSymbol;
    }

    return string;
}

template <typename T>
void CyclicQueue<T>::queueMenu(){

    while(1){
        cout << "1 - add element to queue" << endl << "2 - delete element from queue" << endl << "3 - check if queue is empty" << 
        endl << "4 - print queue"<< endl << "b - go back" << endl;
        char c = getch();
        system("clear");
        switch(c){
            case '1':
                system("clear");
                *this + 0;
                break;
            case '2':
            system("clear");
        try{
                *this - 0;
        }
        catch (std::invalid_argument){
            cout << "Nothing to delete!" << endl;
        }
                break;
            case '3':
                system("clear");
                cout << !(*this) << endl;
                getch();
                system("clear");
                break;
            case '4':
                system("clear");
                printQueue();
                getch();
                system("clear");
                break;
            case 'b':
                system("clear");
                return;
            default:
                cout << "Wrong key" << endl;
                getch();
                system("clear");
        }
    }
}

template <typename T>
void CyclicQueue<T>::operator+(int ignored){

    QueueElement<T>* newElement = new QueueElement<T>;
    newElement->element = enterValue();

    if (ptrFirst == nullptr){

        newElement->ptrNext = newElement;

        ptrFirst = newElement;
        ptrLast = newElement;

        cout << "Added" << endl;
        amountElements++;
        return;
    }

    if (ptrFirst == ptrLast){

        newElement->ptrNext = ptrFirst;
        ptrFirst->ptrNext = newElement;

        ptrLast = newElement;

        cout << "Added" << endl;
        amountElements++;
        return;
    }

    newElement->ptrNext = ptrFirst;
    ptrLast->ptrNext = newElement;
    ptrLast = newElement;
    amountElements++;

    cout << "Added" << endl;
    return;
}

template <typename T>
void CyclicQueue<T>::operator+(QueueElement<T>* newElement){

    if (ptrFirst == nullptr){

        newElement->ptrNext = newElement;

        ptrFirst = newElement;
        ptrLast = newElement;

        amountElements++;
        return;
    }

    if (ptrFirst == ptrLast){

        newElement->ptrNext = ptrFirst;
        ptrFirst->ptrNext = newElement;

        ptrLast = newElement;

        amountElements++;
        return;
    }

    newElement->ptrNext = ptrFirst;
    ptrLast->ptrNext = newElement;
    ptrLast = newElement;
    amountElements++;
    return;

}

template <typename T>
void CyclicQueue<T>::operator-(int ignored){

    if (ptrFirst == nullptr)
        throw std::invalid_argument("No items in queue");

    if (ptrFirst == ptrLast){

        delete ptrFirst;
        amountElements--;

        ptrFirst = nullptr;
        ptrLast = nullptr;

        cout << "Deleted" << endl;
        return;
    }

    QueueElement<T>* delElement = ptrFirst;
    ptrFirst = ptrFirst->ptrNext;
    ptrLast->ptrNext = ptrFirst;
    amountElements--;

    delete delElement;
    return;
}

template <>
void CyclicQueue<char *>::operator+(int ignored){

    QueueElement<char *>* newElement = new QueueElement<char *>;
    newElement->element = enterString();

    if (ptrFirst == nullptr){

        newElement->ptrNext = newElement;

        ptrFirst = newElement;
        ptrLast = newElement;

        cout << "Added" << endl;
        amountElements++;
        return;
    }

    if (ptrFirst == ptrLast){

        newElement->ptrNext = ptrFirst;
        ptrFirst->ptrNext = newElement;

        ptrLast = newElement;

        cout << "Added" << endl;
        amountElements++;
        return;
    }

    newElement->ptrNext = ptrFirst;
    ptrLast->ptrNext = newElement;
    ptrLast = newElement;
    amountElements++;

    cout << "Added" << endl;
    return;
}

template <>
void CyclicQueue<char *>::operator-(int ignored){

    if (ptrFirst == nullptr)
        throw std::invalid_argument("No items in queue");


    if (ptrFirst == ptrLast){
        
        delete[] ptrFirst->element;
        delete ptrFirst;
        amountElements--;

        ptrFirst = nullptr;
        ptrLast = nullptr;

        cout << "Deleted" << endl;
        return;
    }

    QueueElement<char *>* delElement = ptrFirst;
    ptrFirst = ptrFirst->ptrNext;
    ptrLast->ptrNext = ptrFirst;
    amountElements--;

    delete[] delElement->element;
    delete delElement;
    return;
}

/*if queue is empty returns true either false*/
template <typename T>
bool CyclicQueue<T>::operator!(){

    return amountElements == 0;
}
