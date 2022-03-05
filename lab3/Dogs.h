#include "Animals.h"
#include "AnimalsEnum.h"

class Dog final: public Animal{
    public:
    Dog();
    ~Dog();
    friend class ArrayOfCreatures;
};

