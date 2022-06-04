#include "Move.hpp"
#include <cmath>
#include <iostream>

void Move::execute(Field &field) {
    auto h = currentHumanoid.lock();
    if(h){
        h->setPosition(h->getX() + speedX, h->getY() + speedY);
    }
}

Move::Move(const std::shared_ptr<Humanoid> &humanoid, unsigned int desiredX, unsigned int desiredY): Action(humanoid) {
    double angle = atan2((int)desiredY - (int)humanoid->getY(), (int)desiredX - (int)humanoid->getX());
    speedX = humanoid->getX() != desiredX ? round(humanoid->getSpeed() * cos(angle)) : 0;
    speedY = humanoid->getY() != desiredY ? round(humanoid->getSpeed() * sin(angle)) : 0;
}
