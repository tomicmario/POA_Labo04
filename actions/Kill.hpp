#ifndef LABO_04_KILL_HPP
#define LABO_04_KILL_HPP

#include "Action.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Moving action
 */
class Kill : public Action {
public:
    /**
     * Constructor
     * @param humanoid Humanoid to be killed
     */
    explicit Kill(const std::shared_ptr<Humanoid>& humanoid);

    /**
     * Kills the humanoid attached to the class
     * @param field Field where the humanoid is on
     */
    void execute(Field& field) override;

protected:

    /**
     * Attempts to kill the human, if its weak pointer doesn't point to null
     * @param field Field where the humanoid is on
     * @return true if the humanoid is killed, false otherwise
     */
    bool killHumanoid(Field& field);
};


#endif //LABO_04_KILL_HPP
