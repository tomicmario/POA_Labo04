#include "Buffy.hpp"
#include "../controller/Field.hpp"
#include "../controller/util.hpp"
#include "../actions/Kill.hpp"
#include "../actions/Move.hpp"
#include "Humanoid.hpp"

Buffy::Buffy(unsigned x, unsigned y): Humanoid(x,y, 2) {

}

void Buffy::setAction(Field &field) {
    std::shared_ptr<Humanoid> vampire(field.findNearestVampire(shared_from_this()));

    if(vampire){
        double distance = util::getDistance(shared_from_this(), vampire);

        if(distance <= 1.5){
            ac = std::make_shared<Kill>(vampire);
        } else  {
            ac = std::make_shared<Move>(shared_from_this(), vampire->getX(), vampire->getY());
        }
    }
    else {
        unsigned randomX = util::getRandomUnsigned(0, field.getWidth());
        unsigned randomY = util::getRandomUnsigned(0, field.getHeight());
        ac = std::make_shared<Move>(shared_from_this(), randomX, randomY);
    }
}

char Buffy::getSymbol() const {
    return SYMBOL;
}
