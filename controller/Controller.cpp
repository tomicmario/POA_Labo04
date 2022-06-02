//
// Created by ylang on 12.05.2022.
//

#include "Controller.h"

Controller::Controller(unsigned size, unsigned humans, unsigned vampires) :
    SIZE(size), HUMANS(humans), VAMPIRES(vampires), field(size, size){
}

void Controller::run() {

}

void Controller::display() {
    field.display();
}
