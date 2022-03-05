#include "Animals.h"
#include "AnimalsEnum.h"

class Cat final: public Animal{
    Cat();
    ~Cat();
    friend class ArrayOfCreatures;
};