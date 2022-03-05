#include "Animals.h"
#include "AnimalsEnum.h"

class Fish final: public Animal{
public:
    Fish();
    ~Fish();
    friend class ArrayOfCreatures;
private:
};