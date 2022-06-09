#include "Humanoid.hpp"


Humanoid::Humanoid(unsigned x, unsigned y, unsigned speed)
: alive(true), x(x), y(y), speed(speed) {

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

void Humanoid::setPosition(unsigned newx, unsigned newy) {
    this->x = newx;
    this->y = newy;
}

void Humanoid::setAlive(bool alive) {
    this->alive = alive;
}



