#ifndef LABO_04_KILL_HPP
#define LABO_04_KILL_HPP

#include "Action.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Moving action
 */
class Kill : public Action {
public:
    explicit Kill(const std::shared_ptr<Humanoid>& humanoid);
    virtual void execute(Field& field) override;
protected:
    bool killHumanoid(Field& field);
};


#endif //LABO_04_KILL_HPP
