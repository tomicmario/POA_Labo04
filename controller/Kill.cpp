#include "Kill.hpp"
#include "../humanoid/Vampire.hpp"
#include "../graphics/Field.hpp"

Kill::Kill(const std::shared_ptr<Humanoid>& humanoid) : Action(humanoid) {

}

void Kill::execute(Field& field) {
    std::shared_ptr<Humanoid> ptr = currentHumanoid.lock();
    if(ptr){
        if(ptr->isAlive()) {
            ptr->setAlive(false);
            if(dynamic_cast<Vampire*>(ptr.get()) != nullptr){
                field.vampireKilled();
            } else {
                field.humanKilled();
            }
        }
    }
}


