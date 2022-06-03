//
// Created by ylang on 12.05.2022.
//

#include "Vampire.hpp"

Vampire::Vampire(unsigned int speed) : Humanoid()

{}

void Vampire::setAction(Field &field) {
    x++;
}

char Vampire::getSymbol() const {
    return SYMBOL;
}
