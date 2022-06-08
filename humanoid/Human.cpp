#include "Human.hpp"
#include "../actions/Move.hpp"
#include "../controller/Util.hpp"
#include "../controller/Field.hpp"

Human::Human(unsigned x, unsigned y): Humanoid(x,y){

}

void Human::setAction(Field &field) {
    unsigned randomX = Util::getRandomUnsigned(0, field.getWidth());
    unsigned randomY = Util::getRandomUnsigned(0, field.getHeight());
    ac = std::make_shared<Move>(shared_from_this(), randomX, randomY);
}

char Human::getSymbol() const {
    return SYMBOL;
}
