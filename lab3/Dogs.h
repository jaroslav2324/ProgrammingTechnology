#include "Animals.h"
#include "AnimalsEnum.h"

class Dog final: public Animal{
    public:
    Dog();
    Dog(int ignored): Animal{0}{typeOfCreature = Dog_enum;};
    ~Dog();
    friend class ArrayOfCreatures;
};

