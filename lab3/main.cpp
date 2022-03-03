#include <exception>
#include <iostream>
#include <fstream>
#include <vector>

#include "Mammals.h"
#include "Humans.h"
#include "Dogs.h"
#include "Cats.h"
#include "Fishes.h"

using namespace std;

int main(){

    vector<Mammals*> arrayOfObjects;

}

/*You must open binary file before!!!*/
void readArrayOfObjectsFromFile(vector<Mammals*> array, fstream file){

    if (!(file.is_open())){
        throw invalid_argument("File was not opened!");
        return;
    }
    
    if (typeid(...) == typeid(Fish)){

    }
    else if (typeid(...) == typeid(Cat)){

    }
    else if (typeid(...) == typeid(Dog)){

    }
    else if(typeid(...) == typeid(Human)){

    }


}

void writeArrayOfObjectsToFile(vector<Mammals*> array, fstream file){


    for (Mammals* object : array){

    }
}