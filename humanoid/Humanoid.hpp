#ifndef LABO_04_HUMANOID_HPP
#define LABO_04_HUMANOID_HPP

#include <memory>
#include "../actions/Action.hpp"

class Field;
class Action;

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Abstract class serving as a basis of all humanoids.
 */
class Humanoid : public std::enable_shared_from_this<Humanoid> {
public:

    /**
     * Virtual destructor for inherited classes
     */
    virtual ~Humanoid() = default;

    /**
     * Getter for the X position of the humanoid
     * @return X position of the humanoid
     */
    unsigned getX() const;

    /**
     * Getter for the Y position of the humanoid
     * @return Y position of the humanoid
     */
    unsigned getY() const;

    /**
     * Getter for the speed of the humanoid
     * @return speed of the humanoid
     */
    unsigned getSpeed() const;

    /**
     * Getter to determine if a humanoid is alive or not
     * @return True if the humanoid is alive, false otherwise
     */
    bool isAlive() const;

    /**
     * Getter for the char representing the humanoid
     * @return The char representing the humanoid
     */
    virtual char getSymbol() const = 0;

    /**
     * Sets the position of the humanoid
     * @param x X coordinate
     * @param y Y coordinate
     */
    void setPosition(unsigned x, unsigned y);

    /**
     * Sets the alive status of a human
     * @param alive The alive status of a human
     */
    void setAlive(bool alive);

    /**
     * Executes the action given to the humanoid
     * @param field Field where the humanoid is on
     */
    void executeAction(Field& field);

    /**
     * Sets the action for the humanoid
     * @param field Field where the humanoid is on
     */
    virtual void setAction(Field& field) = 0;

protected:
    /**
     * Constructor of the humanoid
     * @param x X coordinate
     * @param y Y coordinate
     * @param speed Speed of the humanoid
     */
    Humanoid(unsigned x, unsigned y, unsigned speed = 1);

    unsigned x;
    unsigned y;
    unsigned speed;
    bool alive;
    std::shared_ptr<Action> ac;
};



#endif //LABO_04_HUMANOID_HPP
