//
// Created by mario on 04/06/2022.
//

#include "Transform.hpp"
#include "../controller/util.hpp"
#include "../graphics//Field.hpp"

Transform::Transform(const std::shared_ptr<Humanoid>& humanoid) : Kill(humanoid) {

}

void Transform::execute(Field &field) {
    if(killHumanoid(field)) {
        unsigned random = util::getRandomUnsigned(0, 2);
        auto ptr = currentHumanoid.lock();
        if(random && ptr){
            field.addVampire(ptr->getX(), ptr->getY());
        }
    }
}