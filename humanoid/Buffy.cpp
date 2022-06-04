//
// Created by ylang on 12.05.2022.
//

#include "Buffy.hpp"
#include "../graphics/Field.hpp"

Buffy::Buffy(unsigned x, unsigned y): Humanoid(x,y) {

}

void Buffy::setAction(Field &field) {


}

char Buffy::getSymbol() const {
    return SYMBOL;
}
