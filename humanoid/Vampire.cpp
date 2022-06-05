//
// Created by ylang on 12.05.2022.
//

#include "Vampire.hpp"
#include "../controller/Field.hpp"
#include "../controller/util.hpp"
#include "../actions//Transform.hpp"
#include "../actions/Move.hpp"
#include "Humanoid.hpp"

Vampire::Vampire(unsigned x, unsigned y): Humanoid(x,y){

}

void Vampire::setAction(Field &field) {
    std::shared_ptr<Humanoid> human(field.findNearestHuman(shared_from_this()));
    if(human != nullptr){
        double distance = util::getDistance(shared_from_this(), human);
        if(distance <= 1.0){
            ac = std::make_shared<Transform>(human);
        } else  {
            ac = std::make_shared<Move>(shared_from_this(), human->getX(), human->getY());
        }
    }
    else {
        ac = std::make_shared<Move>(shared_from_this(), x, y);
    }
}

char Vampire::getSymbol() const {
    return SYMBOL;
}
