#ifndef LABO_04_VAMPIRE_HPP
#define LABO_04_VAMPIRE_HPP

#include "Humanoid.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Vampire specialisation of a humanoid
 */
class Vampire : public Humanoid {
public:

    /**
     * Constructor
     * @param x X coordinate
     * @param y Y coordinate
     */
    Vampire(unsigned x, unsigned y);

    /**
     * Looks for the closest human.
     * - If the human is close enough, the set action will be to transform the human
     * - If there's no human, the set action will be to be still
     * - Otherwise, the set action will be moving towards the closest human
     * @param field Field where the humanoid is on
     */
    void setAction(Field& field) override;

    /**
     * Getter for the char representing the vampire
     * @return The char representing the vampire
     */
    char getSymbol() const override;
private:
    static const char SYMBOL = 'V';
};



#endif //LABO_04_VAMPIRE_HPP
