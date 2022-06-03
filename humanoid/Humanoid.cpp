//
// Created by ylang on 12.05.2022.
//

#include "Humanoid.h"

unsigned int Humanoid::staticId = 0;

Humanoid::Humanoid(char symbol)
: id(staticId++), alive(true), SYMBOL(symbol) {

}

void Humanoid::setPosition(){
    this->x = 0;
    this->y = 0;
}

void Humanoid::executeAction(Field field) {

}
void Humanoid::setAction(Field field) {

}

bool Humanoid::isAlive() const{
    return alive;
}

char Humanoid::getSymbol() const{
    return SYMBOL;
}

Humanoid::~Humanoid() = default;


