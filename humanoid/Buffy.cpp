#include <cmath>
#include "Buffy.hpp"
#include "../controller/Field.hpp"
#include "../controller/Util.hpp"
#include "../actions/Kill.hpp"
#include "../actions/Move.hpp"


Buffy::Buffy(unsigned x, unsigned y): Humanoid(x,y, 2) {

}

void Buffy::setAction(Field &field) {
    std::shared_ptr<Humanoid> vampire(field.findNearestVampire(shared_from_this()));

    if(vampire){
        double distance = Util::getDistance(shared_from_this(), vampire);

        if(std::round(distance) <= 1){
            ac = std::make_shared<Kill>(vampire);
        } else  {
            ac = std::make_shared<Move>(shared_from_this(), vampire->getX(), vampire->getY());
        }
    }
    else {
        speed = 1;
        unsigned randomX = Util::getRandomUnsigned(0, field.getWidth());
        unsigned randomY = Util::getRandomUnsigned(0, field.getHeight());
        ac = std::make_shared<Move>(shared_from_this(), randomX, randomY);
    }
}

char Buffy::getSymbol() const {
    return SYMBOL;
}
