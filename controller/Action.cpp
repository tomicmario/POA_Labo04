#include "Action.hpp"
#include "../humanoid/Humanoid.hpp"

Action::Action(const std::shared_ptr<Humanoid>& humanoid) {
    currentHumanoid = humanoid;
}
