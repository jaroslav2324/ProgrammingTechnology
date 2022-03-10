#include <iostream>

#include "Humans.h"

Human::Human(){
    typeOfCreature = Human_enum;

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << std::endl << "Enter birthDate: " << std::endl;
    std::cin >> birthDate;
    std::cout << std::endl << "Enter nationality: " << std::endl;
    std::cin >> nationality;
    std::cout << std::endl;
    return;
}

Human::~Human(){
    
}

void Human::showDescription(){
    std::cout << std::endl << "Description of this animal:" << std::endl;
    std::cout << std::endl<< "Name: " << name << std::endl << "Birth date: " << birthDate << std::endl << "Nationality " << nationality << std::endl << std::endl;
}