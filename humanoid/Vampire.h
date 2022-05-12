//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_VAMPIRE_H
#define LABO_04_VAMPIRE_H


#include "Humanoid.h"

class Vampire : public Humanoid{
public:
    Vampire(unsigned int speeed);
private:
    unsigned int id;
    static unsigned int staticId;
};
unsigned int Vampire::staticId = 0;


#endif //LABO_04_VAMPIRE_H
