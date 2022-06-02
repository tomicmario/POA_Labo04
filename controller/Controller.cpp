//
// Created by ylang on 12.05.2022.
//

#include "Controller.h"

Controller::Controller(unsigned size, unsigned humans, unsigned vampires) :
    SIZE(size), HUMANS(humans), VAMPIRES(vampires), field(size, size), round(0){
    field.fill();
}

void Controller::run() {
    display();
}

void Controller::display() {
    field.display();
    std::cout << "[" << round << "] q)uit s)tatistics n)ext :" << std::endl;
}
