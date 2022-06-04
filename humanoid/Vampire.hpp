//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_VAMPIRE_HPP
#define LABO_04_VAMPIRE_HPP


#include "Humanoid.hpp"

class Vampire : public Humanoid{
public:
    Vampire(unsigned x, unsigned y);
    void setAction(Field& field) override;
    char getSymbol() const override;
private:
    static const char SYMBOL = 'V';
};



#endif //LABO_04_VAMPIRE_HPP
