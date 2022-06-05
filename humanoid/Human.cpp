//
// Created by ylang on 12.05.2022.
//

#include "Human.hpp"
#include "../actions/Move.hpp"
#include "../controller/util.hpp"
#include "../controller/Field.hpp"

Human::Human(unsigned x, unsigned y): Humanoid(x,y){

}

void Human::setAction(Field &field) {
    unsigned randomX = util::getRandomUnsigned(0, field.getWidth());
    unsigned randomY = util::getRandomUnsigned(0, field.getHeight());
    ac = std::make_shared<Move>(shared_from_this(), randomX, randomY);
}

char Human::getSymbol() const {
    return SYMBOL;
}
