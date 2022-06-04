//
// Created by mario on 03/06/2022.
//

#ifndef LABO_04_MOVE_HPP
#define LABO_04_MOVE_HPP


#include "Action.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Moving action
 */
class Move : public Action{
public:
    explicit Move(const std::shared_ptr<Humanoid>& humanoid, unsigned desiredX, unsigned desiredY);
    void execute(Field& field) override;
private:
    int speedX;
    int speedY;
};


#endif //LABO_04_MOVE_HPP
