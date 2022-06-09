#ifndef LABO_04_FIELD_HPP
#define LABO_04_FIELD_HPP

#include <list>
#include <memory>
#include "../humanoid/Humanoid.hpp"

/**
 * @authors Lange Yanik, Tomic Mario
 * @brief Controller, handling the user-to-machine interaction
 */
class Field {
public:
    /**
     * Constructor of the field
     * @param height Height
     * @param width Width
     * @param humans Amount of humans to generate
     * @param vampires Amount of vampires to generate
     */
    Field(unsigned height, unsigned width, unsigned humans, unsigned vampires);

    /**
     * Destructor
     */
    ~Field();

    /**
     * Disabled copy constructor and affectation operator
     */
    Field(const Field& other) = delete;
    Field& operator=(const Field& other) = delete;

    /**
     * Getter for the amount of vampires left
     * @return The amount of vampires left
     */
    unsigned getVampiresLeft() const;

    /**
     * Getter for the amount of vampires left
     * @return The amount of vampires left
     */
    unsigned getHumansLeft() const;

    /**
     * @return width of the field
     */
    unsigned getWidth() const;

    /**
     * @return height of the field
     */
    unsigned getHeight() const;

    /**
     * Returns the humanoid smart pointer of the closest human to a given humanoid
     * @param searcher Humanoid looking for the closest human
     * @return Humanoid shared pointer of the closest human
     */
    std::shared_ptr<Humanoid> findNearestHuman(const std::shared_ptr<Humanoid>& searcher) const;

    /**
     * Returns the humanoid smart pointer of the closest vampire to a given humanoid
     * @param searcher Humanoid looking for the closest vampire
     * @return Humanoid shared pointer of the closest vampire
     */
    std::shared_ptr<Humanoid> findNearestVampire(const std::shared_ptr<Humanoid>& searcher) const;

    /**
     * Signals to the Field that a human was killed
     */
    void humanKilled();

    /**
     * Signals to the Field that a vampire was killed
     */
    void vampireKilled();

    /**
     * Creates a new vampires
     * @param x X coordinate where the vampire will be created
     * @param y Y coordinate where the vampire will be created
     */
    void addVampire(unsigned x, unsigned y);

    /**
     * Initialises the
     */
    void initialise();

    /**
     * Displays the current state of the field
     */
    void display() const;

    /**
     * Simulates one step of the simulation
     * @return Amount of turns that passed
     */
    unsigned nextTurn();

private:
    const unsigned HEIGHT;
    const unsigned WIDTH;
    const unsigned VAMPIRES;
    const unsigned HUMANS;
    const char LEFT_RIGHT_LIMITERS = '|';
    const char TOP_BOTTOM_LIMITERS = '-';
    const char CORNER_LIMITERS = '+';

    unsigned humans;
    unsigned vampires;
    unsigned int turn;
    std::list<std::shared_ptr<Humanoid>> humanoids;
    char **values;

    /**
     * Fills the display array with empty chars
     */
    void fill() const;

    /**
     * Sets the symbol of humanoids on their coordinates for the display
     */
    void setHumanoidsDisplay() const;

    /**
     * Prints the line at the top and bottom of the field
     */
    void displayTopBottom() const;

    /**
     * Generates a given amount of vampires with random coordinates
     * @param amount Amount of vampires
     */
    void generateVampires(unsigned amount);

    /**
     * Generates a given amount of humans with random coordinates
     * @param amount Amount of humans
     */
    void generateHumans(unsigned amount);

    /**
     * Generates the one and only Buffy
     */
    void generateBuffy();

    /**
     * Allocates a 2-dimensional char array for the display
     */
    void initialiseDisplay();

    /**
     * Destroys the dynamically allocated char array for the display
     */
    void clearDisplay();

    /**
     * Returns the humanoid smart pointer of the closest X to a given humanoid
     * X being a sub-class of Humanoid
     * @param searcher Humanoid looking for the closest X
     * @param func Function that determines if the given humanoid is of X type
     * @return Humanoid smart pointer of the closest X to a given humanoid
     */
    template<class T>
    std::shared_ptr<Humanoid>
    nearestX(const std::shared_ptr<Humanoid>& searcher) const;
};


#endif //LABO_04_FIELD_HPP
