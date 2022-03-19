#include "Animals.h"
#include "AnimalsEnum.h"

class Cat final: public Animal{
    public:
    Cat();
    Cat(int ignored): Animal{0}{typeOfCreature = Cat_enum;};
    ~Cat();
    friend class ArrayOfCreatures;
};