#include <iostream>
#include <string>

#include "Mammals.h"

class Human final: public Mammals{

    public:
    Human();
    ~Human();
    void showDescription() override;

    private:
    std::string name;
    std::string birthDate;
    std::string nationality;
};