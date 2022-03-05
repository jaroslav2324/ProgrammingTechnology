#include <iostream>
#include <fstream>
#include <vector>

#include "Mammals.h"

class ArrayOfCreatures{

public:
    ArrayOfCreatures();
    ~ArrayOfCreatures();

private:
    void readArrayOfObjectsFromFile(std::fstream file);
    void writeArrayOfObjectsToFile(std::fstream file);
    std::vector<Mammals*> array;
    int amountAnimals;
};
