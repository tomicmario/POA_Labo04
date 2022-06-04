//
// Created by ylang on 12.05.2022.
//

#include "Vampire.hpp"
#include "../graphics/Field.hpp"
#include "../controller/util.hpp"
#include "../controller/Kill.hpp"

Vampire::Vampire(unsigned x, unsigned y): Humanoid(x,y){

}

void Vampire::setAction(Field &field) {
    std::shared_ptr<Human> human(field.findNearestHuman(shared_from_this()));
    if(human != nullptr){
        if(util::getDistance(shared_from_this(), human) >= 2){
            // set move
        }
        else {
            ac = std::make_shared<Kill>(human);
        }
    }
}

char Vampire::getSymbol() const {
    return SYMBOL;
}
