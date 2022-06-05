#include "Action.hpp"

Action::Action(const std::shared_ptr<Humanoid>& humanoid) {
    currentHumanoid = humanoid;
}
