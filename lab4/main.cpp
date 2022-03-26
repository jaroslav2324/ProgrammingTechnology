#include <iostream>
#include <conio.h>
#include "MergeSort.h"
#include "CyclicQueue.h"

using std::cout;
using std::endl;

int main(){

    char c;
    while(1){

        cout << "1 - work with Merge Sort" << endl << "2 - work with Cyclic Queue" << endl << "Q - exit" << endl;

        c = getch();
        
        switch(c){
        case '1':
            cout << "1 - create and sort int values" << endl << "2 - create and sort char values" << endl << "3 - create and sort float values" << endl <<
            "4 - create and sort double values" << endl << "5 - create and sort char* values" << endl << "b - go back" << endl;
            
            c = getch();
            switch(c){
            case '1':{

            }
                break;
            case '2':{

            }
                break;
            case '3':{

            }
                break;
            case '4':{

            }
                break;
            case '5':{

            }
                break;
            case 'b':
                break;
            default:
                cout << "Wrong key" << endl;
            }
            break;
        case '2':
            cout << "1 - create int queue and work with it" << endl << "2 - create char queue and work with it" << endl << 
            "3 - create float queue and work with it" << endl << "4 - create double queue and work with it" << endl << "5 - create char* queue and work with it" << 
            "b - go back" << endl;
             c = getch();
            switch(c){
            case '1':{

            }
                break;
            case '2':{

            }
                break;
            case '3':{

            }
                break;
            case '4':{

            }
                break;
            case '5':{
                
            }
                break;
            case 'b':
                break;
            default:
                cout << "Wrong key" << endl;
            }
        case 'b':
            break;
        case 'Q':
            exit(0);
        case '\n':
            break;
        default:
            cout << "Wrong key!" << endl;
        }

    }

    return 0;
}