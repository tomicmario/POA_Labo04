//
// Created by ylang on 12.05.2022.
//

#include "Humanoid.hpp"


Humanoid::Humanoid(unsigned x, unsigned y)
: alive(true), x(x), y(y) {

}


void Humanoid::executeAction(Field& field) {
    if(ac != nullptr){
        ac->execute(field);
    }
}


bool Humanoid::isAlive() const{
    return alive;
}


unsigned Humanoid::getX() const {
    return x;
}

unsigned Humanoid::getY() const {
    return y;
}

unsigned Humanoid::getSpeed() const {
    return speed;
}

void Humanoid::setPosition(unsigned x, unsigned y) {
    this->x = x;
    this->y = y;
}

void Humanoid::setAlive(bool alive) {
    this->alive = alive;
}

Humanoid::~Humanoid() = default;


