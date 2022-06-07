#include "Move.hpp"
#include <cmath>

void Move::execute(Field &field) {
    auto humanoid = currentHumanoid.lock();
    if(humanoid){
        humanoid->setPosition(humanoid->getX() + speedX, humanoid->getY() + speedY);
    }
}

Move::Move(const std::shared_ptr<Humanoid>& humanoid, unsigned desiredX, unsigned desiredY): Action(humanoid) {
    speedX = 0;
    speedY = 0;
    if(desiredX == humanoid->getX() && desiredY == humanoid->getY()){
        speedX = desiredX == 0 ? 1 : -1;
        return;
    }

    // Movement decomposition
    for(unsigned i = 0; i < humanoid->getSpeed(); ++i) {
        double angle = atan2(speedY + (long)desiredY - (long)humanoid->getY(),
                             speedX + (long)desiredX - (long)humanoid->getX());
        // vector rotation of a (x,y) vector, where x = humanoid speed and y = 0 -> speedX = cos(angle), speedY = sin(angle)
        speedX += round(cos(angle));
        speedY += round(sin(angle));
    }
}
