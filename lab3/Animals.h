#include <string>

#include "Mammals.h"

class Animal : public Mammals{
    public:
    Animal();
    ~Animal();
    friend class ArrayOfCreatures;
    void showDescription();    
    private:
    std::string breed;
    std::string name;
    std::string colour;
    std::string ownerName;
    std::string size;
};