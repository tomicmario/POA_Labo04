#ifndef LABO_04_KILL_HPP
#define LABO_04_KILL_HPP

#include "Action.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Moving action
 */
class Kill : public Action {
public:
    Kill(const std::shared_ptr<Humanoid>& humanoid);
    void execute(Field& field) override;
};


#endif //LABO_04_KILL_HPP
