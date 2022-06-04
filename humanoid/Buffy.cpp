//
// Created by ylang on 12.05.2022.
//

#include "Buffy.hpp"
#include "../graphics/Field.hpp"
#include "../controller/util.hpp"
#include "../controller/Kill.hpp"
#include "../controller/Move.hpp"
#include "Humanoid.hpp"

Buffy::Buffy(unsigned x, unsigned y): Humanoid(x,y, 2) {

}

void Buffy::setAction(Field &field) {
    std::shared_ptr<Humanoid> vampire(field.findNearestVampire(shared_from_this()));
    if(vampire != nullptr){
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
