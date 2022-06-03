//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_HUMANOID_HPP
#define LABO_04_HUMANOID_HPP


#include "../graphics/Field.hpp"

class Field;

class Humanoid {
public:
    virtual ~Humanoid();
    void setPosition();
    unsigned getX() const;
    unsigned getY() const;
    unsigned getSpeed() const;

    void executeAction(Field field);

    void setAction(Field field);

    bool isAlive() const;
    char getSymbol() const;

protected:
    Humanoid(char symbol);
    unsigned x;
    unsigned y;
    unsigned speed;
    unsigned int id;
    static unsigned int staticId;
    bool alive;
    const char SYMBOL;

};



#endif //LABO_04_HUMANOID_HPP
