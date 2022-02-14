#include <conio.h>

#include "Queue.h"
#include "DerievedPublic.h"
#include "DerievedPrivate.h"
#include "DerievedProtected.h"

using namespace std;

int main(){
    
    Queue* currentQueue;
    DerPublic publicQueue;
    DerPrivate privateQueue; 
    DerProtected protectedQueue; 

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
                    currentQueue = (Queue*)(&privateQueue);
                    break;
                case '3':
                    currentQueue = (Queue*)(&protectedQueue);
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
            {
                Queue* q1ptr,* q2ptr;
                cout << "Choose queues:\n1 - public queue\n2 - private queue\n3 - protected queue\n";
                cout << "First queue:\n";

                char c1 = getch();
                if (!(c1 == '1' || c1 == '2' || c1 == '3'))
                {
                    cout << "Wrong num of queue" << endl;
                    break;
                }
                switch(c1){
                    case '1':
                        q1ptr = &publicQueue;
                        break;
                    case '2':
                        q1ptr = (Queue*)(&privateQueue);
                        break;
                    case '3':
                        q1ptr = (Queue*)(&protectedQueue);
                        break;
                }
                cout << "Second queue:\n";

                char c2 = getch();

                if (!(c2 == '1' || c2 == '2' || c2 == '3'))
                {
                    cout << "Wrong num of queue" << endl;
                    break;
                }
                switch(c2){
                    case '1':
                        q2ptr = &publicQueue;
                        break;
                    case '2':
                        q2ptr = (Queue*)(&privateQueue);
                        break;
                    case '3':
                        q2ptr = (Queue*)(&protectedQueue);
                        break;
                }

                Queue* newQueue = mergeQueues(q1ptr, q2ptr);
                printQueue(newQueue);

                cout << "Enter operation" << endl;
                break;
            }
            case 'Q':
                cout << "Exiting" << endl;
                return 0;
            default:
                cout << "Wrong key" << endl;
                cout << "Enter operation" << endl;
        }
    }
    
}