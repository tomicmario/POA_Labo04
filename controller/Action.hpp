#ifndef LABO_04_ACTION_HPP
#define LABO_04_ACTION_HPP


#include "../graphics/Field.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Abstract class serving as a basis for actions that humanoids can perform
 */
class Action {
public:
    virtual ~Action() = default;
    virtual void execute(Field& field) = 0;
protected:
    explicit Action(const Humanoid& humanoid);
    const Humanoid* humanoid;
};


#endif //LABO_04_ACTION_HPP
