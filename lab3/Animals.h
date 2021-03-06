#pragma once

#include <string>

#include "Mammals.h"

class Animal : public Mammals{
    public:
    Animal();
    Animal(int ignored);
    ~Animal();
    friend class ArrayOfCreatures;
    void showDescription();    
    void changeDescription();
    protected:
    std::string breed;
    std::string name;
    std::string colour;
    std::string ownerName;
    std::string size;
};