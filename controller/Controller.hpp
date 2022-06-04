#ifndef LABO_04_CONTROLLER_HPP
#define LABO_04_CONTROLLER_HPP


#include "../graphics/Field.hpp"
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
    double stats = 0.0;
    const unsigned SIMULATIONS_AMOUNT = 10000;
    Field field;
    unsigned round;
    void display();
    void nextFrame();
    void runFullSimulation();
};


#endif //LABO_04_CONTROLLER_HPP
