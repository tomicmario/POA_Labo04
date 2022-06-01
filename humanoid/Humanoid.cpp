//
// Created by ylang on 12.05.2022.
//

#include "Humanoid.h"

unsigned int Humanoid::staticId = 0;

Humanoid::Humanoid()
: id(staticId++), alive(true)
{

}

void Humanoid::setPosition(){
    this->x = 0;
    this->y = 0;
}

void Humanoid::executeAction(Field field) {

}
void Humanoid::setAction(Field field) {

}

bool Humanoid::isAlive() {
    return alive;
}

