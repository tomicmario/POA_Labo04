//
// Created by ylang on 12.05.2022.
//

#ifndef LABO_04_HUMANOID_HPP
#define LABO_04_HUMANOID_HPP


#include "../graphics/Field.hpp"
#include <memory>
#include "../controller/Action.hpp"

class Field;
class Action;

class Humanoid : public std::enable_shared_from_this<Humanoid> {
public:
    Humanoid();
    virtual ~Humanoid();
    void setPosition(unsigned x, unsigned y);
    unsigned getX() const;
    unsigned getY() const;
    unsigned getSpeed() const;

    void executeAction(Field& field);

    virtual void setAction(Field& field) = 0;

    bool isAlive() const;
    virtual char getSymbol() const = 0;

protected:
    unsigned x;
    unsigned y;
    unsigned speed;

    bool alive;
    std::weak_ptr<Action> ac;
};



#endif //LABO_04_HUMANOID_HPP
