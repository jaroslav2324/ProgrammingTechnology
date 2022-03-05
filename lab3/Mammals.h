#pragma once

class Mammals{
    protected:
    virtual void showDescription() = 0;
    int typeOfCreature;
    friend class ArrayOfCreatures;
};