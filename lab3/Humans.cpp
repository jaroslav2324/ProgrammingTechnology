#include <iostream>

#include "Humans.h"

Human::Human(){
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