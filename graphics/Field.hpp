//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_FIELD_HPP
#define LABO_04_FIELD_HPP


#include <list>

#include "../humanoid/Humanoid.hpp"

class Humanoid;

class Field {
public:
    Field(unsigned int height, unsigned int width);
    ~Field();
    void display() const;
    void fill() const;
    void update() const;
    int nextTurn();
    Human* findNearestHuman(const Humanoid& searcher);
    Vampire* findNearestVampire(const Humanoid& searcher);
private:
    unsigned int height;
    unsigned int width;
    const char LEFT_RIGHT_LIMITERS = '|';
    const char TOP_BOTTOM_LIMITERS = '-';
    const char CORNER_LIMITERS = '+';

    unsigned int turn;
    std::list<Humanoid*> humanoids;

    char **values;

    static double getDistance(unsigned x1, unsigned y1, unsigned x2, unsigned y2);
};


#endif //LABO_04_FIELD_HPP
