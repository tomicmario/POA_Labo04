//
// Created by ylang on 12.05.2022.
//

#include "Human.hpp"
#include "../controller/Move.hpp"

Human::Human(unsigned x, unsigned y): Humanoid(x,y){

}

void Human::setAction(Field &field) {
    ac = std::make_shared<Move>(shared_from_this());
}

char Human::getSymbol() const {
    return SYMBOL;
}
