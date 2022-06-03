#ifndef LABO_04_KILL_HPP
#define LABO_04_KILL_HPP

#include "Action.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Moving action
 */
class Kill : public Action {
    explicit Kill(const Humanoid& humanoid);
    void execute(Field& field) override;
};


#endif //LABO_04_KILL_HPP