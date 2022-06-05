#include "Kill.hpp"
#include "../humanoid/Vampire.hpp"
#include "../controller/Field.hpp"

Kill::Kill(const std::shared_ptr<Humanoid>& humanoid) : Action(humanoid) {

}

void Kill::execute(Field& field) {
    killHumanoid(field);
}

bool Kill::killHumanoid(Field& field) {
    std::shared_ptr<Humanoid> humanoid = currentHumanoid.lock();

    if(humanoid){
        if(humanoid->isAlive()) {
            humanoid->setAlive(false);

            // Verifies if the humanoid is a vampire
            if(dynamic_cast<Vampire*>(humanoid.get()) != nullptr){
                field.vampireKilled();
            } else {
                field.humanKilled();
            }
            return true;
        }
    }
    return false;
}


