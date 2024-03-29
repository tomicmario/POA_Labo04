#include <iostream>
#include "controller/Controller.hpp"

bool debug = true;

using namespace std;

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Entry point of the application, taking the different parameters
 */
int main(int argc, char *argv[]) {
    int fieldSize = 50;
    int humanAmount = 20;
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
            cout << "All given arguments must be strictly positive" << endl;
            return EXIT_SUCCESS;
        }

        if(fieldSize < 2){
            cout << "The field size must be at least two" << endl;
            return EXIT_SUCCESS;
        }
    }

    Controller c((unsigned)fieldSize, (unsigned)humanAmount, (unsigned)vampireAmount);
    c.run();

    return EXIT_SUCCESS;
}
