//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_BUFFY_HPP
#define LABO_04_BUFFY_HPP


#include "Humanoid.hpp"

class Buffy : public Humanoid {
public:
    Buffy(unsigned x, unsigned y);
    void setAction(Field& field) override;
    char getSymbol() const override;
private:
    static const char SYMBOL = 'B';
};


#endif //LABO_04_BUFFY_HPP
