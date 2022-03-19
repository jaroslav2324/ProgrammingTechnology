#include "Animals.h"
#include "AnimalsEnum.h"

class Fish final: public Animal{
public:
    Fish();
    Fish(int ignored): Animal{0}{typeOfCreature = Fish_enum;};
    ~Fish();
    friend class ArrayOfCreatures;
private:
};