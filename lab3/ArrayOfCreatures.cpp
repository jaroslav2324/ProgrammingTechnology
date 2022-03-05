#include "ArrayOfCreatures.h"
#include "AnimalsEnum.h"
#include "Mammals.h"
#include "Humans.h"
#include "Dogs.h"
#include "Cats.h"
#include "Fishes.h"


/*You must open binary file before!!!*/
void ArrayOfCreatures::readArrayOfObjectsFromFile(std::fstream file){

    if (!(file.is_open())){
        throw std::invalid_argument("File was not opened!");
        return;
    }

    file >> amountAnimals;
    
    char animal; 
    for (int i = 0; i < amountAnimals; i++){
        file >> animal;
        switch (animal){
        case Human_enum:
            class Human* humanPtr = new class Human;
            file >> humanPtr->name >> humanPtr->nationality >> humanPtr->birthDate;
            array.push_back(humanPtr);
            break;
        case Dog_enum:
            class Dog* dogPtr = new class Dog;
            file >> dogPtr->name >> dogPtr->breed >> dogPtr->colour >> dogPtr->ownerName >> dogPtr->size;
            array.push_back(dogPtr);
            break;
        case Cat_enum:
            class Cat* catPtr = new class Cat;
            file >> catPtr->name >> catPtr->breed >> catPtr->colour >> catPtr->ownerName >> catPtr->size;
            array.push_back(catPtr);
            break;
        case Fish_enum:
            class Fish* fishPtr = new class Fish;
            file >> fishPtr->name >> fishPtr->breed >> fishPtr->colour >> fishPtr->ownerName >> fishPtr->size;
            array.push_back(fishPtr);
            break;
        default:
            std::cout << "Error while reading file" << std::endl;
            break;
        }
    }

    return;
}

void ArrayOfCreatures::writeArrayOfObjectsToFile(std::fstream file){

    if (!(file.is_open())){
        throw std::invalid_argument("File was not opened!");
        return;
    }

    file << amountAnimals;

    for (const auto* creature: array){
        if (creature->typeOfCreature == Human_enum){
            file << Human_enum;
            Human* humanPtr = (Human*)creature;
            file << humanPtr->name << humanPtr->nationality << humanPtr->birthDate;
            continue;
        }
        if (creature->typeOfCreature == Dog_enum){
            file << Dog_enum;
            Dog* dogPtr = (Dog*)creature;
            file << dogPtr->name << dogPtr->breed << dogPtr->colour << dogPtr->ownerName << dogPtr->size;
            continue;
        }
        if (creature->typeOfCreature == Cat_enum){
            file << Cat_enum;
            Cat* catPtr = (Cat*)creature;
            file << catPtr->name << catPtr->breed << catPtr->colour << catPtr->ownerName << catPtr->size;
            continue;
        }
        if (creature->typeOfCreature == Fish_enum){
            file << Fish_enum;
            Fish* fishPtr = (Fish*)creature;
            file << fishPtr->name << fishPtr->breed << fishPtr->colour << fishPtr->ownerName << fishPtr->size;
            continue;
        }
    }

    return;
    
}