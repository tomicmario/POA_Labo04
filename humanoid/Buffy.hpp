#ifndef LABO_04_BUFFY_HPP
#define LABO_04_BUFFY_HPP

#include "Humanoid.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Buffy specialisation of a humanoid
 */
class Buffy : public Humanoid {
public:
    /**
     * Constructor
     * @param x X coordinate
     * @param y Y coordinate
     */
    Buffy(unsigned x, unsigned y);

    /**
     * Looks for the closest Vampire.
     * - If the Vampire is close enough, the set action will be to kill the Vampire
     * - If there's no Vampire, the set action will be to move towards a random point of the map
     * - Otherwise, the set action will be moving towards the closest Vampire
     * @param field Field where the humanoid is on
     */
    void setAction(Field& field) override;

    /**
     * Getter for the char representing Buffy
     * @return The char representing Buffy
     */
    char getSymbol() const override;
private:
    static const char SYMBOL = 'B';
};


#endif //LABO_04_BUFFY_HPP
