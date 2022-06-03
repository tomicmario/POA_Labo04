//
// Created by ylang on 12.05.2022.
//

#include "Buffy.hpp"

Buffy::Buffy(): Humanoid() {

}

void Buffy::setAction(Field &field) {
    x++;
}

char Buffy::getSymbol() const {
    return SYMBOL;
}
