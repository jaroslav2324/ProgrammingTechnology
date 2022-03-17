#include <iostream>

#include "Mammals.h"

using std::cout;
using std::endl;

int Mammals::amountMammals = 0;

Mammals::Mammals(){

    amountMammals++;
    return;
}

Mammals::~Mammals(){
    
    amountMammals--;
    return;
}

void Mammals::setAmountMammals(int amount){

    amountMammals = amount;
    return;
}

void Mammals::printAmountMammals(){

    cout << Mammals::amountMammals << endl;
    return;
}