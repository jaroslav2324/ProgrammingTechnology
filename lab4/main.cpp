#include <iostream>
#include <conio.h>

#include "MergeSort.h"
#include "CyclicQueue.h"

using std::cout;
using std::endl;

template <typename T>
void fillArrayWithRandomNumbers(T* array, int size);

template <typename T>
void printArray(T* array, int size);

template <>
void fillArrayWithRandomNumbers(float* array, int size){
    for (int i = 0; i < size; i++){
        array[i] = rand() % 51;
        array[i] += (float)(rand() % 100) / (float)100;
    }
}

template <>
void fillArrayWithRandomNumbers(double* array, int size){
    for (int i = 0; i < size; i++){
        array[i] = rand() % 51;
        array[i] += (double)(rand() % 100) / (double)100;
    }
}

void fillArrayWithRandomStrings(char** array, int size);
void printStringArray(char** array, int size);
void deleteStringsInArray(char** array, int size);


int main(){

    srand(time(0));

    char c;
    while(1){

        cout << "1 - work with Merge Sort" << endl << "2 - work with Cyclic Queue" << endl << "Q - exit" << endl;

        c = getch();
        
        switch(c){
        case '1':
            system("clear");

            cout << "1 - create and sort int values" << endl << "2 - create and sort char values" << endl << "3 - create and sort float values" << endl <<
            "4 - create and sort double values" << endl << "5 - create and sort char* values" << endl << "b - go back" << endl;
            
            c = getch();
            switch(c){
            case '1':{
                system("clear");

                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                int array[size];

                fillArrayWithRandomNumbers(array, size);
                printArray(array, size);

                cout << endl << "Starting sorting" << endl;
                mergeSort(array, 0, size - 1);

                printArray(array, size);
                getch();
                system("clear");
            }
                break;
            case '2':{
                system("clear");

                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                char array[size];

                fillArrayWithRandomNumbers(array, size);
                printArray(array, size);

                cout << endl << "Starting sorting" << endl;
                mergeSort(array, 0, size - 1);

                printArray(array, size);
                getch();
                system("clear");
            }
                break;
            case '3':{
                system("clear");

                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                float array[size];

                fillArrayWithRandomNumbers(array, size);
                printArray(array, size);

                cout << endl << "Starting sorting" << endl;
                mergeSort(array, 0, size - 1);

                printArray(array, size);
                getch();
                system("clear");
            }
                break;
            case '4':{
                system("clear");

                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                double array[size];

                fillArrayWithRandomNumbers(array, size);
                printArray(array, size);

                cout << endl << "Starting sorting" << endl;
                mergeSort(array, 0, size - 1);

                printArray(array, size);
                getch();
                system("clear");
            }
                break;
            case '5':{
                system("clear");
                
                int size;
                cout << "Enter size of array" << endl;
                size = enterUint();

                char** array = new char*[size];

                fillArrayWithRandomStrings(array, size);
                printStringArray(array, size);

                cout << endl << "Starting sorting" << endl;
                mergeSort(array, 0, size - 1);

                printStringArray(array, size);
                getch();
                system("clear");

                deleteStringsInArray(array, size);
            }
                break;
            case 'b':
                break;
            default:
                cout << "Wrong key" << endl;
            }
            break;
        case '2':
            system("clear");
            cout << "1 - create int queue and work with it" << endl << "2 - create char queue and work with it" << endl << 
            "3 - create float queue and work with it" << endl << "4 - create double queue and work with it" << endl << "5 - create char* queue and work with it" << endl << 
            "b - go back" << endl;
             c = getch();
            switch(c){
            case '1':{
                system("clear");
                CyclicQueue<int> queue;
                queue.queueMenu();
            }
                break;
            case '2':{
                system("clear");
                CyclicQueue<char> queue;
                system("clear");
                queue.queueMenu();
            }
                break;
            case '3':{
                system("clear");
                CyclicQueue<float> queue;
                system("clear");
                queue.queueMenu();
            }
                break;
            case '4':{
                system("clear");
                CyclicQueue<double> queue;
                system("clear");
                queue.queueMenu();
            }
                break;
            case '5':{
                system("clear");
                CyclicQueue<char*> queue;
                system("clear");
                queue.queueMenu();
            }
                break;
            case 'b':
                system("clear");
                break;
            default:
                system("clear");
                cout << "Wrong key" << endl;

                getch();
                system("clear");
            }
            break;
        case 'Q':
            exit(0);
        case '\n':
            break;
        default:
            system("clear");
            cout << "Wrong key!" << endl;
            getch();
            system("clear");
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
    cout << endl;
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
            while (asciiCode < 48 || (asciiCode > 57 && asciiCode < 65) || (asciiCode > 90 && asciiCode < 97) || asciiCode > 122)
                asciiCode = rand() % 256;
            string[j] = asciiCode;
        }
        array[i] = string;
    }
}

void printStringArray(char** array, int size){
    for (int i = 0; i < size; i++)
        cout << array[i];
}

void deleteStringsInArray(char** array, int size){

    for (int i = 0; i < size; i++)
        delete[] array[i];
}
