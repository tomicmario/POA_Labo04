#include "Transform.hpp"
#include "../controller/util.hpp"
#include "../controller/Field.hpp"

Transform::Transform(const std::shared_ptr<Humanoid>& humanoid) : Kill(humanoid) {

}

void Transform::execute(Field &field) {
    if(killHumanoid(field)) {
        unsigned random = util::getRandomUnsigned(0, 2);
        auto human = currentHumanoid.lock();
        if(random && human){
            field.addVampire(human->getX(), human->getY());
        }
    }
}