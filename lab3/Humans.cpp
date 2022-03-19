#include <iostream>

#include "Humans.h"

Human::Human(){
    typeOfCreature = Human_enum;

    changeDescription();
    return;
}
/*with no initialistation*/
Human::Human(int ignored){

}

Human::~Human(){
    
}

void Human::changeDescription(){

    std::cout << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << std::endl << "Enter birthDate: " << std::endl;
    std::cin >> birthDate;
    std::cout << std::endl << "Enter nationality: " << std::endl;
    std::cin >> nationality;
    std::cout << std::endl << "Added" << std::endl;
    return;
}

void Human::showDescription(){

    std::cout << "Type: human" << std::endl;
    std::cout << std::endl << "Description of this human:" << std::endl;
    std::cout << std::endl<< "Name: " << name << std::endl << "Birth date: " << birthDate << std::endl << "Nationality: " << nationality << std::endl << std::endl;
}