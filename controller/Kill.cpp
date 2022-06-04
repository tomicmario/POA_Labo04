#include "Kill.hpp"
#include "../humanoid/Humanoid.hpp"

Kill::Kill(const std::shared_ptr<Humanoid>& humanoid) : Action(humanoid) {

}

void Kill::execute(Field& field) {
    auto ptr = currentHumanoid.lock();
    if(ptr != nullptr){
        ptr->setAlive(false);
    }
}


