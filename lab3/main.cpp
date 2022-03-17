#include <fstream>
#include <conio.h>

#include "Mammals.h"
#include "Humans.h"
#include "Dogs.h"
#include "Cats.h"
#include "Fishes.h"
#include "ArrayOfCreatures.h"

using std::cout;
using std::endl;

int main(){

    const char* filename = "/home/user/gitprojects/ProgrammingTechnology/lab3/file.txt";

    ArrayOfCreatures array;

    array.readArrayOfObjectsFromFile(filename);

    cout << "1 - add a human to array" << endl << "2 - add a cat to array" << endl << "3 - add a dog to array" << endl << "4 - add a fish to array" << endl;
    cout << "5 - delete chosen creature" << endl << "6 - choose creature in array" << endl << "7 - show description of a creature" << endl;
    cout << "8 - show description of all creatures" << endl << "9 - print amount of creatures" << endl;
    //change creature;


        while(1){
        char c = getch();

        switch(c){
            case '\n':
                break;
            case '1':
            {
                cout << "Adding a human" << endl;
                Human* newHuman = new Human;
                array.addToArray(newHuman);
                break; 
            }
            case '2':
            {
                cout << "Adding a cat" << endl;
                Cat* newCat = new Cat;
                array.addToArray(newCat);
                break; 
            }
            case '3':
            {
                cout << "Adding a dog" << endl;
                Dog* newDog = new Dog;
                array.addToArray(newDog);
                break; 
            }
            case '4':
            {
                cout << "Adding a fish" << endl;
                Fish* newFish = new Fish;
                array.addToArray(newFish);
                break; 
            }
            case '5':
            {
                cout << "Deleting chosen creature" << endl;
                array.deleteElement();
                break;
            }
            case '6':
                cout << "Choosing a creature" << endl;
                array.chooseCreature();
                break;
            case '7':
                array.showDescription();
                break;
            case '8':
                array.showAllDescriptions();
                break;
            case '9':
                Mammals::printAmountMammals();
                break;
            case 'Q':
                array.writeArrayOfObjectsToFile(filename);
                return 0;
            default:
                cout << "Wrong key" << endl;
        }
    }


}
