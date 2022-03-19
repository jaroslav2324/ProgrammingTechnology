#include <cstring>
#include <random>
#include <exception>
#include <cstring>

#include "ArrayOfCreatures.h"
#include "AnimalsEnum.h"
#include "Mammals.h"
#include "Humans.h"
#include "Dogs.h"
#include "Cats.h"
#include "Fishes.h"

using std::cout;
using std::endl;
using std::numeric_limits;

int enterint(){

    int num;

    std::cout << "Enter usigned int number" << std::endl;
    std::cin >> num;

    while (!(std::cin.good())){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong number! Try once again!" << std::endl; 
        std::cout << "Enter unsigned int number" << std::endl;
        std::cin >> num;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return num;
}

char* readline(std::fstream& file, char* buffer, int lenbuff){

    file.getline(buffer, lenbuff);
    if (strlen(buffer) == lenbuff || strlen(buffer) == lenbuff - 1)
        throw std::invalid_argument("String buffer overflowed!");
    return buffer;
}

ArrayOfCreatures::ArrayOfCreatures(){

    array = new Mammals*[resizeValue]{nullptr};
    sizeArray += resizeValue;
    return;
}

ArrayOfCreatures::~ArrayOfCreatures(){

    for (int i = 0; i < amountAnimals; i++){
        if (array[i] == nullptr)
            continue;
        delete(array[i]);
    }

    delete array;
    return;
}

void ArrayOfCreatures::addToArray(Mammals* creature){

    if (numChosenAnimal == -1){
        array[0] = creature;
        numChosenAnimal = 0;
        ++amountAnimals;
        return;
    } 

    if (amountAnimals == sizeArray || amountAnimals > sizeArray)
        resizeArray();

    for (int i = 0; i <= amountAnimals; i ++){
        if (array[i] == nullptr){
            array[i] = creature;
            ++amountAnimals;
            return;
        }
    }

    return;
}

void ArrayOfCreatures::resizeArray(){

    while (amountAnimals >= sizeArray)
            sizeArray += resizeValue;

    Mammals** newArr = new Mammals*[sizeArray];
    memset(newArr, 0, sizeArray * sizeof(Mammals*));
	memcpy(newArr, array, (sizeArray - resizeValue) * sizeof(Mammals*));
    delete(array);
    array = newArr;
}

void ArrayOfCreatures::chooseCreature(){

    int num = -1;

    while(num < 0 || num >= sizeArray){
        num = enterint();
        if (array[num] == nullptr){
            num = -1;
            cout << "Wrong number! Creature with this number does not exist!" << endl;
            continue;
        }
    }
    numChosenAnimal = num;
    cout << "Chosen " << numChosenAnimal << " animal" << endl;
    return;
}

void ArrayOfCreatures::deleteElement(){

    if (numChosenAnimal == -1){
        cout << "Nothing to delete!" << endl;
        return;
    }

    delete(array[numChosenAnimal]);
    array[numChosenAnimal] = nullptr;
    --amountAnimals;
    findNearestToChooseAfterDeleting();
}

void ArrayOfCreatures::findNearestToChooseAfterDeleting(){
    int counterL = numChosenAnimal, counterR = numChosenAnimal;

    for (int i = counterL; i >= 0; i--){
        if (array[i] != nullptr){
            counterL = i;
            break;
        }
    }

    for (int i = counterR; i < amountAnimals; i++){
        if (array[i] != nullptr){
            counterR = i;
            break;
        }
    }

    if (counterR == counterL){
        numChosenAnimal = -1;
        return;
    }

    if (counterR == numChosenAnimal){
        numChosenAnimal = counterL;
        return;
    }

    if (counterL == numChosenAnimal){
        numChosenAnimal = counterR;
        return;
    }

    if (counterR - numChosenAnimal < numChosenAnimal - counterL){
        numChosenAnimal = counterR;
        return;
    }
    else{
        numChosenAnimal = counterL;
        return;
    }

    return;
}

void ArrayOfCreatures::showDescription(){

    if (numChosenAnimal == -1){
        cout << "No chosen animal" << endl;
        return;
    }
    
    array[numChosenAnimal]->showDescription();
    return;
}

void ArrayOfCreatures::showAllDescriptions(){

    if (amountAnimals == 0){
        cout << "No animals in array" << endl;
        return;
    }

    for (int i = 0; i < sizeArray; i++)
        if (array[i] != nullptr){
            cout << "Number in array: " << i << endl;
            array[i]->showDescription();
        }
    
    return;
}

void ArrayOfCreatures::readArrayOfObjectsFromFile(const char filename[]){

    std::fstream file(filename, std::ios::in);
    char buffer[100];

    if (!(file.is_open()))
        throw std::invalid_argument("File was not opened!");
     
    if (file.eof())
        return;

    readline(file, buffer, 100);
    amountAnimals = atoi(buffer);

    if (file.eof())
        return;

    int animal; 

    for (int i = 0; i < amountAnimals; i++){

        readline(file, buffer, 100);
        animal = atoi(buffer);

        switch (animal){
        case Human_enum:
            {
                class Human* humanPtr = new class Human(0);
                readline(file, buffer, 100);
                std::string str(buffer);
                humanPtr->name = str;
                readline(file, buffer, 100);
                std::string str2(buffer);
                humanPtr->nationality = str2;
                readline(file, buffer, 100);
                std::string str3(buffer);
                humanPtr->birthDate = str3;
                addToArray(humanPtr);
                amountAnimals--;
                break;
            }
        case Dog_enum:
            {
                class Dog* dogPtr = new class Dog(0);
                readline(file, buffer, 100);
                std::string str(buffer);
                dogPtr->name = str;
                readline(file, buffer, 100);
                std::string str2(buffer);
                dogPtr->breed = str2;
                readline(file, buffer, 100);
                std::string str3(buffer);
                dogPtr->colour = str3;
                readline(file, buffer, 100);
                std::string str4(buffer);
                dogPtr->ownerName = str4;
                readline(file, buffer, 100);
                std::string str5(buffer);
                dogPtr->size = str5;
                addToArray(dogPtr);
                amountAnimals--;
                break;
            }
        case Cat_enum:
            {
                class Cat* catPtr = new class Cat(0);
                readline(file, buffer, 100);
                std::string str(buffer);
                catPtr->name = str;
                readline(file, buffer, 100);
                std::string str2(buffer);
                catPtr->breed = str2;
                readline(file, buffer, 100);
                std::string str3(buffer);
                catPtr->colour = str3;
                readline(file, buffer, 100);
                std::string str4(buffer);
                catPtr->ownerName = str4;
                readline(file, buffer, 100);
                std::string str5(buffer);
                catPtr->size = str5;
                addToArray(catPtr);
                amountAnimals--;                
                break;
            }
        case Fish_enum:
            {
                class Fish* fishPtr = new class Fish(0);
                readline(file, buffer, 100);
                std::string str(buffer);
                fishPtr->name = str;
                readline(file, buffer, 100);
                std::string str2(buffer);
                fishPtr->breed = str2;
                readline(file, buffer, 100);
                std::string str3(buffer);
                fishPtr->colour = str3;
                readline(file, buffer, 100);
                std::string str4(buffer);
                fishPtr->ownerName = str4;
                readline(file, buffer, 100);
                std::string str5(buffer);
                fishPtr->size = str5;
                addToArray(fishPtr);
                amountAnimals--;                
                break;
            }
        default:
            std::cout << "Error while reading file" << std::endl;
            break;
        }
    }

    file.close();

    return;
}

void ArrayOfCreatures::writeArrayOfObjectsToFile(const char filename[]){

    std::fstream file(filename, std::ios::out | std::ios::trunc);

    if (!(file.is_open())){
        throw std::invalid_argument("File was not opened!");
        return;
    }

    file << amountAnimals << endl;

    for (int i =0; i < sizeArray; i++){
        if (array[i] == nullptr)
            continue;
        if (array[i]->typeOfCreature == Human_enum){
            file << Human_enum << endl;
            Human* humanPtr = (Human*)array[i];
            file << humanPtr->name << endl << humanPtr->nationality << endl << humanPtr->birthDate << endl;
            continue;
        }
        if (array[i]->typeOfCreature == Dog_enum){
            file << Dog_enum << endl;
            Dog* dogPtr = (Dog*)array[i];
            file << dogPtr->name << endl << dogPtr->breed << endl << dogPtr->colour << endl << dogPtr->ownerName << endl << dogPtr->size << endl;
            continue;
        }
        if (array[i]->typeOfCreature == Cat_enum){
            file << Cat_enum << endl;
            Cat* catPtr = (Cat*)array[i];
            file << catPtr->name << endl << catPtr->breed << endl << catPtr->colour << endl << catPtr->ownerName << endl << catPtr->size << endl;
            continue;
        }
        if (array[i]->typeOfCreature == Fish_enum){
            file << Fish_enum << endl;
            Fish* fishPtr = (Fish*)array[i];
            file << fishPtr->name << endl << fishPtr->breed << endl << fishPtr->colour << endl << fishPtr->ownerName << endl << fishPtr->size << endl;
            continue;
        }
    }

    file.close();

    return;
    
}

void ArrayOfCreatures::changeCreature(){

    if (numChosenAnimal == -1){
        cout << "Nothing to edit!" << endl;
        return;
    }
    if (array[numChosenAnimal]->typeOfCreature == Human_enum)
        ((Human*)array[numChosenAnimal])->changeDescription();
    if (array[numChosenAnimal]->typeOfCreature == Dog_enum)
        ((Dog*)array[numChosenAnimal])->changeDescription();
    if (array[numChosenAnimal]->typeOfCreature == Cat_enum)
        ((Cat*)array[numChosenAnimal])->changeDescription();
    if (array[numChosenAnimal]->typeOfCreature == Fish_enum)
        ((Fish*)array[numChosenAnimal])->changeDescription();
    return;
}
