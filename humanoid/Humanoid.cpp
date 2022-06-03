//
// Created by ylang on 12.05.2022.
//

#include "Humanoid.hpp"


Humanoid::Humanoid()
: alive(true) {

}


void Humanoid::executeAction(Field& field) {
    auto wp = ac.lock();
    if(wp != nullptr){
        wp->execute(field);
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

Humanoid::~Humanoid() = default;


