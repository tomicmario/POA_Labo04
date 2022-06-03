//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_HUMAN_HPP
#define LABO_04_HUMAN_HPP


#include "Humanoid.h"

class Human : public Humanoid{
public:
    Human();
private:
    unsigned int id;
    static unsigned int staticId;
    static const char SYMBOL = 'h';
};


#endif //LABO_04_HUMAN_HPP
