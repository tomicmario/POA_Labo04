#ifndef LABO_04_MOVE_HPP
#define LABO_04_MOVE_HPP

#include "Action.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Moving action
 */
class Move : public Action{
public:
    /**
     * Constructor of the move action
     * @param humanoid Humanoid to move
     * @param desiredX Desired X coordinate where humanoid wants to move to
     * @param desiredY Desired Y coordinate where humanoid wants to move to
     */
    explicit Move(const std::shared_ptr<Humanoid>& humanoid, unsigned desiredX, unsigned desiredY);

    /**
     * Moves the humanoid on the field
     * @param field Field where the humanoid is on
     */
    void execute(Field& field) override;

private:
    long speedX;
    long speedY;
};


#endif //LABO_04_MOVE_HPP
