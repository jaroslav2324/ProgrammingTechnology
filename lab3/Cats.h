#include "Animals.h"
#include "AnimalsEnum.h"

class Cat final: public Animal{
    public:
    Cat();
    Cat(int ignored);
    ~Cat();
    friend class ArrayOfCreatures;
};