#include <iostream>

#include "AnimalsEnum.h"
#include "Animals.h"

Animal::Animal(){

    std::cout << std::endl << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter breed: " << std::endl;
    std::cin >> breed;
    std::cout << std::endl << "Enter colour: " << std::endl;
    std::cin >> colour;
    std::cout << std::endl << "Enter owner name: " << std::endl;
    std::cin >> ownerName;
    std::cout << std::endl << "Enter size: " << std::endl;
    std::cin >> size;
    std::cout << std::endl << "Added" << std::endl;
}

Animal::Animal(int ignored){

}

Animal::~Animal(){
    
}

void Animal::showDescription(){

        switch(this->typeOfCreature){
        case Dog_enum:
            std::cout << "Type: dog" << std::endl;
            break;
        case Cat_enum:
            std::cout << "Type: cat" << std::endl;
            break;
        case Fish_enum:
            std::cout << "Type: fish" << std::endl;
            break;
    }
    std::cout << std::endl << "Description of this animal:" << std::endl;
    std::cout << "Breed: " << breed << std::endl<< "Name: " << name << std::endl << "Colour " << colour << std::endl << "Owner Name: " << ownerName << std::endl << "Size: " << size << std::endl << std::endl;
}