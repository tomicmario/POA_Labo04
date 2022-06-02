//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_CONTROLLER_H
#define LABO_04_CONTROLLER_H


#include "../graphics/Field.h"
#include <iostream>

class Controller {
public:
    Controller(unsigned size, unsigned humans, unsigned vampires);
    void run();
private:
    const unsigned SIZE;
    const unsigned HUMANS;
    const unsigned VAMPIRES;
    const Field field;
    unsigned round;
    void display();
};


#endif //LABO_04_CONTROLLER_H
