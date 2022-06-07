#include "Move.hpp"
#include <cmath>

void Move::execute(Field &field) {
    auto humanoid = currentHumanoid.lock();
    if(humanoid){
        humanoid->setPosition(humanoid->getX() + speedX, humanoid->getY() + speedY);
    }
}

Move::Move(const std::shared_ptr<Humanoid>& humanoid, unsigned desiredX, unsigned desiredY): Action(humanoid) {
    if(desiredX == humanoid->getX() && desiredY == humanoid->getY()){
        speedX = desiredX == 0 ? 1 : -1;
        speedY = 0;
        return;
    }
    double angle = atan2((long)desiredY - (long)humanoid->getY(), (long)desiredX - (long)humanoid->getX());
    // vector rotation of a (x,y) vector, where x = humanoid speed and y = 0 -> speedX = cos(angle), speedY = sin(angle)
    double idealSpeedX = humanoid->getSpeed() * cos(angle);
    double idealSpeedY = humanoid->getSpeed() * sin(angle);

    long maxSpeedX = (long)desiredX - (long)humanoid->getX();
    long maxSpeedY = (long)desiredY - (long)humanoid->getY();

    speedX = abs(maxSpeedX) < humanoid->getSpeed() ? maxSpeedX: round(idealSpeedX);
    speedY = abs(maxSpeedY) < humanoid->getSpeed() ? maxSpeedY: round(idealSpeedY);
}
