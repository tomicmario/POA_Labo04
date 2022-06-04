#ifndef LABO_04_ACTION_HPP
#define LABO_04_ACTION_HPP


#include <memory>
#include "../humanoid/Humanoid.hpp"
class Humanoid;
class Field;
/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Abstract class serving as a basis for actions that humanoids can perform
 */
class Action {
public:
    virtual ~Action() = default;
    virtual void execute(Field& field) = 0;
    Action(const std::shared_ptr<Humanoid>& humanoid);
protected:
    std::weak_ptr<Humanoid> currentHumanoid;
};


#endif //LABO_04_ACTION_HPP
