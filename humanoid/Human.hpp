#ifndef LABO_04_HUMAN_HPP
#define LABO_04_HUMAN_HPP

#include "Humanoid.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Human specialisation of a humanoid
 */
class Human : public Humanoid {
public:
    /**
     * Constructor
     * @param x X coordinate
     * @param y Y coordinate
     */
    Human(unsigned x, unsigned y);

    /**
     * Sets the action of moving towards a point selected randomly on the field
     * @param field Field where the humanoid is on
     */
    void setAction(Field& field) override;

    /**
     * Getter for the char representing the human
     * @return The char representing the human
     */
    char getSymbol() const override;
private:
    static const char SYMBOL = 'h';
};


#endif //LABO_04_HUMAN_HPP
