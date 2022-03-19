#pragma once

#include <iostream>
#include <fstream>

#include "Mammals.h"

class ArrayOfCreatures{

public:
    ArrayOfCreatures();
    ~ArrayOfCreatures();
    void addToArray(Mammals* creature);
    void chooseCreature();
    void deleteElement();
    void readArrayOfObjectsFromFile(const char filename[]);
    void writeArrayOfObjectsToFile(const char filename[]);
    void showDescription();
    void showAllDescriptions();
    void changeCreature();
private:
    Mammals** array = nullptr;
    int amountAnimals = 0;
    int resizeValue = 10;
    int sizeArray = 0;
    int numChosenAnimal = -1;
    void resizeArray();
    void findNearestToChooseAfterDeleting();
    friend int enterint();
    friend char* readline(std::fstream& file, char* buffer, int lenbuff);
};
