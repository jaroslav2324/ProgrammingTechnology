#include <cstring>
#include <random>
#include <exception>

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

    if (amountAnimals == sizeArray)
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

    sizeArray += resizeValue;
    Mammals** newArr = new Mammals*[sizeArray];
    memset(newArr, 0, sizeArray * sizeof(Mammals*));
	memcpy(newArr, array, (sizeArray - resizeValue) * sizeof(Mammals*));
    delete(array);
    array = newArr;
}

void ArrayOfCreatures::chooseCreature(){

    int num = -1;

    while(num < 0 || num >= amountAnimals){
        num = enterint();
        if (array[num] == nullptr){
            num = -1;
            cout << "Wrong number! Creature with this number does not exist!" << endl;
            continue;
        }
    }
    numChosenAnimal = num;
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

    std::fstream file(filename, std::ios::binary | std::ios::in);

    //cout << file.is_open();

    if (!(file.is_open())){
        throw std::invalid_argument("File was not opened!");
        return;
    }

    if (file.eof())
        return;

    file >> amountAnimals;

    if (file.eof())
        return;
    
    char animal; 
    for (int i = 0; i < amountAnimals; i++){
        file >> animal;
        switch (animal){
        case Human_enum:
            {
                class Human* humanPtr = new class Human;
                file >> humanPtr->name >> humanPtr->nationality >> humanPtr->birthDate;
                addToArray(humanPtr);
                break;
            }
        case Dog_enum:
            {
                class Dog* dogPtr = new class Dog;
                file >> dogPtr->name >> dogPtr->breed >> dogPtr->colour >> dogPtr->ownerName >> dogPtr->size;
                addToArray(dogPtr);
                break;
            }
        case Cat_enum:
            {
                class Cat* catPtr = new class Cat;
                file >> catPtr->name >> catPtr->breed >> catPtr->colour >> catPtr->ownerName >> catPtr->size;
                addToArray(catPtr);
                break;
            }
        case Fish_enum:
            {
                class Fish* fishPtr = new class Fish;
                file >> fishPtr->name >> fishPtr->breed >> fishPtr->colour >> fishPtr->ownerName >> fishPtr->size;
                addToArray(fishPtr);
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

    std::fstream file(filename, std::ios::binary | std::ios::out | std::ios::trunc);

    if (!(file.is_open())){
        throw std::invalid_argument("File was not opened!");
        return;
    }

    file << amountAnimals;

    for (int i =0; i < amountAnimals; i++){
        if (array[i]->typeOfCreature == Human_enum){
            file << Human_enum;
            Human* humanPtr = (Human*)array[i];
            file << humanPtr->name << humanPtr->nationality << humanPtr->birthDate;
            continue;
        }
        if (array[i]->typeOfCreature == Dog_enum){
            file << Dog_enum;
            Dog* dogPtr = (Dog*)array[i];
            file << dogPtr->name << dogPtr->breed << dogPtr->colour << dogPtr->ownerName << dogPtr->size;
            continue;
        }
        if (array[i]->typeOfCreature == Cat_enum){
            file << Cat_enum;
            Cat* catPtr = (Cat*)array[i];
            file << catPtr->name << catPtr->breed << catPtr->colour << catPtr->ownerName << catPtr->size;
            continue;
        }
        if (array[i]->typeOfCreature == Fish_enum){
            file << Fish_enum;
            Fish* fishPtr = (Fish*)array[i];
            file << fishPtr->name << fishPtr->breed << fishPtr->colour << fishPtr->ownerName << fishPtr->size;
            continue;
        }
    }

    file.close();

    return;
    
}

