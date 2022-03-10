#include "Animals.h"
#include "AnimalsEnum.h"

class Cat final: public Animal{
    public:
    Cat();
    ~Cat();
    friend class ArrayOfCreatures;
};