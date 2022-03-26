#include <iostream>
#include <conio.h>
#include "MergeSort.h"
#include "CyclicQueue.h"

using std::cout;
using std::endl;

int main(){

    srand(time(0));

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

                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                int array[size];

                fillArrayWithRandomNumbers(array, size);
                printArray(array, size);

                mergeSort(array, 0, size - 1);

                printArray(array, size);
            }
                break;
            case '2':{

                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                char array[size];

                fillArrayWithRandomNumbers(array, size);
                printArray(array, size);

                mergeSort(array, 0, size - 1);

                printArray(array, size);
            }
                break;
            case '3':{

                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                float array[size];

                fillArrayWithRandomNumbers(array, size);
                printArray(array, size);

                mergeSort(array, 0, size - 1);

                printArray(array, size);
            }
                break;
            case '4':{

                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                double array[size];

                fillArrayWithRandomNumbers(array, size);
                printArray(array, size);

                mergeSort(array, 0, size - 1);

                printArray(array, size);
            }
                break;
            case '5':{
                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                char* array[size];

                fillArrayWithRandomStrings(array, size);
                printStringArray(array, size);

                mergeSort(array, 0, size - 1);

                printStringArray(array, size);
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
                CyclicQueue<int> queue;
                queue.queueMenu();
            }
                break;
            case '2':{
                CyclicQueue<char> queue;
                queue.queueMenu();
            }
                break;
            case '3':{
                CyclicQueue<float> queue;
                queue.queueMenu();
            }
                break;
            case '4':{
                CyclicQueue<double> queue;
                queue.queueMenu();
            }
                break;
            case '5':{
                CyclicQueue<char*> queue;
                queue.queueMenu();
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

template <typename T>
void fillArrayWithRandomNumbers(T* array, int size){
    for (int i = 0; i < size; i++)
        array[i] = rand() % 51;
}

template <typename T>
void printArray(T* array, int size){
    for (int i = 0; i < size; i++)
        cout << array[i] << ' ';
}

void fillArrayWithRandomStrings(char** array, int size){

    int stringSize;
    for (int i = 0; i < size; i++){
        stringSize = -1;
        while(stringSize < 2 || stringSize > 50)
            stringSize = rand() % 51;

        char* string = new char[stringSize];
        string[stringSize - 1] = '\n';

        char asciiCode;
        for (int j = 0; j < stringSize - 1; j++){
            asciiCode = -1;
            while (asciiCode < 32 || asciiCode > 126)
                asciiCode = rand() % 256;
            string[j] = asciiCode;
        }
    }
}

void printStringArray(char** array, int size){
    for (int i = 0; i < size; i++)
        cout << array[i] << endl;
}
