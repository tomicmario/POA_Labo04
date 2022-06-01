//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_HUMANOID_H
#define LABO_04_HUMANOID_H


#include "../graphics/Field.h"

class Field;

class Humanoid {
public:
    Humanoid();
    void setPosition();
    unsigned getX() const;
    unsigned getY() const;
    unsigned getSpeed() const;

    void executeAction(Field field);

    void setAction(Field field);

    bool isAlive();

private:
    unsigned x;
    unsigned y;
    unsigned speed;
    unsigned int id;
    static unsigned int staticId;
    bool alive;

};



#endif //LABO_04_HUMANOID_H
