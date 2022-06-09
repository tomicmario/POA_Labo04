#include "Human.hpp"
#include "../actions/Move.hpp"
#include "../controller/Util.hpp"
#include "../controller/Field.hpp"

Human::Human(unsigned x, unsigned y): Humanoid(x,y){

}

void Human::setAction(Field &field) {

    unsigned randomX = Util::getRandomUnsigned( (long)x - (long)speed < 0 ? 0: x - speed,
            (long)x + (long)speed >= field.getWidth() ? field.getWidth() - 1: x + speed);
    unsigned randomY = Util::getRandomUnsigned((long)y - (long)speed < 0 ? 0 : y - speed,
    (long)y + (long)speed >= field.getHeight() ? field.getHeight() - 1 :  y + speed);
    ac = std::make_shared<Move>(shared_from_this(), randomX, randomY);
}

char Human::getSymbol() const {
    return SYMBOL;
}
