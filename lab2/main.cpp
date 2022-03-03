#include <iostream>
#include <conio.h>

#include "Time.h"
#include "List.h"

using namespace std;

int main(){
    srand(time(0));

    List* list = new List;
    Time* time = new Time{};

    cout << "Numbers are used to work with list, letters are used to work with time" << endl;

    cout << "1 - add element in the beginning" << endl << "2 - add element in the end" << endl << "3 - delete element from the beginning" << endl << "4 - delete element from the end" << endl << "5 - print list" << endl;
    cout << "a - increase minutes" << endl << "s - decrease minutes" << endl << "d - multiply time" << endl << " f - divide time" << endl << "g - print time" << endl;
    while(1){
        char c = getch();

        switch(c){
            case '1':
                ++(*list);
                printList(list);
                break;
            case '2':
                (*list)++;
                printList(list);
                break;
            case '3':
                --(*list);
                printList(list);
                break;
            case '4':
                (*list)--;
                printList(list);
                break;
            case '5':
                printList(list);
                break;
            case 'a':
                (*time) + enterint();
                time->printTime();
                break;
            case 's':
                (*time) - enterint();
                time->printTime();
                break;
            case 'd':
                (*time) * enterint();
                time->printTime();
                break;
            case 'f':
                (*time) / enterint();
                time->printTime();
                break;
            case 'g':
                time->printTime();
                break;
            case '\n':
                break;

            case 'Q':
                return 0;
                break;
            default:
                cout << "Wrong key" << endl;
        }
    }
}