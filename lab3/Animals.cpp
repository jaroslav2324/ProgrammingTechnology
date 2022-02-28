#include <iostream>

#include "Animals.h"

Animal::Animal(){
    std::cout << "Enter breed: " << std::endl;
    std::cin >> breed;
    std::cout << std::endl << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << std::endl << "Enter colour: " << std::endl;
    std::cin >> colour;
    std::cout << std::endl << "Enter owner name: " << std::endl;
    std::cin >> ownerName;
    std::cout << std::endl << "Enter size: " << std::endl;
    std::cin >> size;
    std::cout << std::endl;
}

Animal::~Animal(){
    
}

void Animal::showDescription(){
    std::cout << std::endl << "Description of this animal:" << std::endl;
    std::cout << "Breed: " << breed << std::endl<< "Name: " << name << std::endl << "Colour " << colour << std::endl << "Owner Name: " << ownerName << std::endl << "Size: " << size << std::endl << std::endl;
}