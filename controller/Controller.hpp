#ifndef LABO_04_CONTROLLER_HPP
#define LABO_04_CONTROLLER_HPP

#include "Field.hpp"
#include <iostream>

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Controller, handling the user-to-machine interaction
 */
class Controller {
public:
    /**
     * Constructor of the Controller
     * @param size Dimension of the field
     * @param humans Amount of humans to generate
     * @param vampires Amount of vampires to generate
     */
    Controller(unsigned size, unsigned humans, unsigned vampires);

    /**
     * Disabled copy constructor and affectation operator
     */
    Controller(const Controller& other) = delete;
    Controller& operator=(const Controller& other) = delete;


    /**
     * Runs the Controller with blocking calls for the input
     */
    void run();
private:
    double stats = 0.0;
    const unsigned SIMULATIONS_AMOUNT = 10000;
    Field field;
    unsigned round;
    static const char NEXT = 'n';
    static const char QUIT = 'q';
    static const char STATS = 's';

    /**
     * Displays the status of the field and the result of the simulation
     */
    void display();

    /**
     * Executes one step of the current simulation
     */
    void nextFrame();

    /**
     * Runs a full simulation and calculates the percentage of simulations where at least one human survived
     */
    void runFullSimulation();
};


#endif //LABO_04_CONTROLLER_HPP
