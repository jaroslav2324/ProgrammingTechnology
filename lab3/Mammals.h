#pragma once

class Mammals{
public:
    Mammals();
    ~Mammals();
    static void setAmountMammals(int amount);
    static void printAmountMammals();

protected:
    static int amountMammals;

    int typeOfCreature;

    virtual void showDescription() = 0;
    friend class ArrayOfCreatures;
};