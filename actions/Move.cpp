#include "Move.hpp"
#include <cmath>

void Move::execute(Field& field) {
    auto humanoid = currentHumanoid.lock();
    if(humanoid){
        humanoid->setPosition(humanoid->getX() + speedX, humanoid->getY() + speedY);
    }
}

Move::Move(const std::shared_ptr<Humanoid>& humanoid, unsigned desiredX, unsigned desiredY): Action(humanoid) {
    speedX = 0;
    speedY = 0;

    // In the case of the random point being on the same spot as the humanoid
    if(desiredX == humanoid->getX() && desiredY == humanoid->getY()){
        // Goes to the towards the mind bound unless it's there already
        speedX = desiredX ? -1 : 1;
        return;
    }

    // Movement decomposition
    for(unsigned i = 0; i < humanoid->getSpeed(); ++i) {
        // Calculating the angle from two points
        double angle = atan2(speedY + (long)desiredY - (long)humanoid->getY(),
                             speedX + (long)desiredX - (long)humanoid->getX());
        // vector rotation of a (x,y) vector, where x = humanoid speed and y = 0 -> speedX = cos(angle), speedY = sin(angle)
        speedX += round(cos(angle));
        speedY += round(sin(angle));
    }
}
