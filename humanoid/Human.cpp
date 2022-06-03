//
// Created by ylang on 12.05.2022.
//

#include "Human.hpp"

Human::Human(): Humanoid() {

}

void Human::setAction(Field &field) {
    x++;
}

char Human::getSymbol() const {
    return SYMBOL;
}
