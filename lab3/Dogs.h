#include "Animals.h"
#include "AnimalsEnum.h"

class Dog final: public Animal{
    public:
    Dog();
    Dog(int ignored);
    ~Dog();
    friend class ArrayOfCreatures;
};

