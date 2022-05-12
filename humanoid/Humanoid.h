//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_HUMANOID_H
#define LABO_04_HUMANOID_H




class Humanoid {
public:
    Humanoid();
    void setPosition();
    unsigned getX() const;
    unsigned getY() const;
    unsigned getSpeed() const;
private:
    unsigned x;
    unsigned y;
    unsigned speed;
    unsigned int id;
    static unsigned int staticId;
};
unsigned int Humanoid::staticId = 0;


#endif //LABO_04_HUMANOID_H
