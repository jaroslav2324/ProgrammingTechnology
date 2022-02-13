#include <conio.h>

#include "Queue.h"
#include "DerievedPublic.h"
#include "DerievedPrivate.h"
#include "DerievedProtected.h"

using namespace std;

int main(){
    Queue* currentQueue;
    DerPublic publicQueue ;//= new DerPublic;
    DerPrivate privateQueue; //= new DerPrivate;
    DerProtected protectedQueue; //= new DerProtected;

    currentQueue = &publicQueue;

 cout << "c - Choose queue(1 - public, 2 - private, 3 - protected)\n1 - Add element\n2 - Delete element\n3 - Print queue\n4 - Count more average garmonic\n5 - Copy queue\n6 - Merge queues\nQ - Exit\n";
        

    while (1)
    {
        char c = getch();
        switch(c){
            case '\n':
                break;

            case 'c':
            cout << "Enter num of queue" << endl;
            c = getch();
            switch(c){
                case '1':
                    currentQueue = &publicQueue;
                    break;
                case '2':
                    //currentQueue = &privateQueue;
                    break;
                case '3':
                    //currentQueue = &protectedQueue;
                    break;
            }
                cout << "Enter operation" << endl;
                break;
            case '1':
                currentQueue->addElement();
                cout << "Enter operation" << endl;
                break;
            case '2':
                currentQueue->deleteElement();
                cout << "Enter operation" << endl;
                break;
            case '3':
                printQueue(currentQueue);
                cout << "Enter operation" << endl;
                break;
            case '4':
                ((DerPublic *)currentQueue)->countElementsMoreAverage();
                break;
                cout << "Enter operation" << endl;
            case '5':
            {
                Queue* newQueue = currentQueue->copyQueue();
                cout << endl << currentQueue << ' ';
                printQueue(currentQueue);
                cout << newQueue << ' ';
                printQueue(newQueue);
                newQueue->~Queue();
            }
                cout << "Enter operation" << endl;
                break;
            case '6':
                cout << "Enter operation" << endl;
                break;
            case 'Q':
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Wrong key" << endl;
                cout << "Enter operation" << endl;
        }
    }
    
}