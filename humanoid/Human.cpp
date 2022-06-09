#include "Human.hpp"
#include "../actions/Move.hpp"
#include "../controller/Util.hpp"
#include "../controller/Field.hpp"

Human::Human(unsigned x, unsigned y): Humanoid(x,y){

}

void Human::setAction(Field &field) {
    unsigned minX = (long)x - (long)speed < 0 ? 0: x - speed;
    unsigned maxX = (long)x + (long)speed >= field.getWidth() ? field.getWidth() : x + speed;
    unsigned minY = (long)y - (long)speed < 0 ? 0 : y - speed;
    unsigned maxY = (long)y + (long)speed >= field.getHeight() ? field.getHeight() :  y + speed;
    unsigned randomX = Util::getRandomUnsigned(minX, maxX);
    unsigned randomY = Util::getRandomUnsigned(minY, maxY);
    ac = std::make_shared<Move>(shared_from_this(), randomX, randomY);
}

char Human::getSymbol() const {
    return SYMBOL;
}
