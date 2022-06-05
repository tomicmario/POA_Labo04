#include "Move.hpp"
#include <cmath>

void Move::execute(Field &field) {
    auto humanoid = currentHumanoid.lock();
    if(humanoid){
        humanoid->setPosition(humanoid->getX() + speedX, humanoid->getY() + speedY);
    }
}

Move::Move(const std::shared_ptr<Humanoid> &humanoid, unsigned int desiredX, unsigned int desiredY): Action(humanoid) {
    double angle = atan2((int)desiredY - (int)humanoid->getY(), (int)desiredX - (int)humanoid->getX());
    // vector rotation of a (x,y) vector, where x = humanoid speed and y = 0 -> speedX = cos(angle), speedY = sin(angle)
    // if the desired coordinate is the same, the speed is set to 0
    speedX = humanoid->getX() != desiredX ? round(humanoid->getSpeed() * cos(angle)) : 0;
    speedY = humanoid->getY() != desiredY ? round(humanoid->getSpeed() * sin(angle)) : 0;
}
