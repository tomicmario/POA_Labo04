//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_VAMPIRE_H
#define LABO_04_VAMPIRE_H


#include "Humanoid.h"

class Vampire : public Humanoid{
public:
    Vampire(unsigned int speed);
private:
    unsigned int id;
    static unsigned int staticId;
    static const char SYMBOL = 'V';
};
unsigned int Vampire::staticId = 0;


#endif //LABO_04_VAMPIRE_H
