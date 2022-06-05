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
    /**
     * Constructor of the class
     * @param humanoid Humanoid that will have the action executed on
     */
    Action(const std::shared_ptr<Humanoid>& humanoid);

    /**
     * Virtual destructor for inheritance
     */
    virtual ~Action() = default;

    /**
     * Executes the action
     * @param field Field where the humanoid is on
     */
    virtual void execute(Field& field) = 0;

protected:
    std::weak_ptr<Humanoid> currentHumanoid;
};


#endif //LABO_04_ACTION_HPP
