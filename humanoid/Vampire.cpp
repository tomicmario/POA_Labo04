#include "Vampire.hpp"
#include "../controller/Field.hpp"
#include "../controller/Util.hpp"
#include "../actions//Transform.hpp"
#include "../actions/Move.hpp"
#include "Humanoid.hpp"

Vampire::Vampire(unsigned x, unsigned y): Humanoid(x,y){

}

void Vampire::setAction(Field &field) {
    std::shared_ptr<Humanoid> human(field.findNearestHuman(shared_from_this()));

    if(human){
        double distance = Util::getDistance(shared_from_this(), human);

        if(distance <= 1.0){
            ac = std::make_shared<Transform>(human);
        } else  {
            ac = std::make_shared<Move>(shared_from_this(), human->getX(), human->getY());
        }
    }
    else {
        // Immobile
        ac = nullptr;
    }
}

char Vampire::getSymbol() const {
    return SYMBOL;
}
