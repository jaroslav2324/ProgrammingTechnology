#include <iostream>
#include <string>

#include "ArrayOfCreatures.h"
#include "AnimalsEnum.h"
#include "Mammals.h"

class Human final: public Mammals{

    public:
    friend class ArrayOfCreatures;
    Human();
    Human(int ignored);
    ~Human();
    void showDescription() override;
    void changeDescription();

    private:
    std::string name;
    std::string birthDate;
    std::string nationality;
};