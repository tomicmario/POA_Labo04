//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_FIELD_H
#define LABO_04_FIELD_H


#include <list>
#include "../humanoid/Humanoid.h"

class Humanoid;

class Field {
public:
    Field(unsigned int height, unsigned int width);
    void display() const;
    void update() const;
    int nextTurn();
private:
    unsigned int height;
    unsigned int width;
    const char LEFT_RIGHT_LIMITERS = '|';
    const char TOP_BOTTOM_LIMITERS = '-';
    const char CORNER_LIMITERS = '+';

    unsigned int turn;
    std::list<Humanoid*> humanoids;
};


#endif //LABO_04_FIELD_H
