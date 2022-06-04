//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_HUMAN_HPP
#define LABO_04_HUMAN_HPP


#include "Humanoid.hpp"

class Human : public Humanoid {
public:
    Human(unsigned x, unsigned y);
    void setAction(Field& field) override;
    char getSymbol() const override;
private:
    static const char SYMBOL = 'h';
};


#endif //LABO_04_HUMAN_HPP
