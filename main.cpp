#include <iostream>
#include "graphics/Field.h"

bool debug = true;

using namespace std;

int main(int argc, char *argv[]) {
    int fieldSize = 10;
    int humanAmount = 10;
    int vampireAmount = 10;
    if(!debug) {
        if (argc != 4) {
            cout << "Expected arguments : [<field size>] [<human number>] [<vampire number>]" << endl;
            return EXIT_SUCCESS;
        }
        fieldSize = atoi(argv[1]);
        humanAmount = atoi(argv[2]);
        vampireAmount = atoi(argv[3]);

        if(fieldSize <= 0 || humanAmount <= 0 || vampireAmount <= 0){
            cout << "All given arguments must be positive" << endl;
            return EXIT_SUCCESS;
        }
        cout << "field size : " << fieldSize << endl
             << "human amount : " << humanAmount << endl
             << "vampire amount : " << vampireAmount << endl;
    }

    Field f(10, 40);
    f.fill();
    f.display();

    return EXIT_SUCCESS;
}
