#ifndef LABO_04_CONTROLLER_H
#define LABO_04_CONTROLLER_H


#include "../graphics/Field.h"
#include <iostream>

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Controller, handling the user-to-machine interaction
 */
class Controller {
public:
    Controller(unsigned size, unsigned humans, unsigned vampires);
    void run();
private:
    const unsigned SIZE;
    const unsigned HUMANS;
    const unsigned VAMPIRES;
    double stats = 0.0;
    const Field field;
    unsigned round;
    void display();
    void nextFrame();
    void runFullSimulation();
};


#endif //LABO_04_CONTROLLER_H
