#include "Move.hpp"
#include <cmath>


void Move::execute(Field &field) {
    auto h = currentHumanoid.lock();
    if(h){
        h->setPosition(h->getX() + speedX, h->getY() + speedY);
    }
}

Move::Move(const std::shared_ptr<Humanoid> &humanoid, unsigned int desiredX, unsigned int desiredY): Action(humanoid) {
    double angle = atan2(humanoid->getY() - desiredY, humanoid->getX() - desiredX) - M_PI / 4;
    speedX = round(humanoid->getSpeed() * cos(angle) - humanoid->getSpeed() * sin(angle));
    speedY = round(humanoid->getSpeed() * sin(angle) + humanoid->getSpeed() * cos(angle));
}
