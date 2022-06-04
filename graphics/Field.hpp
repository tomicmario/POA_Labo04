#ifndef LABO_04_FIELD_HPP
#define LABO_04_FIELD_HPP


#include <list>
#include <memory>

#include "../humanoid/Humanoid.hpp"
#include "../humanoid/Human.hpp"
#include "../humanoid/Vampire.hpp"

class Field {
public:
    Field(unsigned height, unsigned width, unsigned humans, unsigned vampires);
    ~Field();
    void display();
    void update() const;
    int nextTurn();
    std::shared_ptr<Humanoid> findNearestHuman(const std::shared_ptr<Humanoid>& searcher) const;
    std::shared_ptr<Vampire> findNearestVampire(const std::shared_ptr<Humanoid>& searcher) const;
    void initialise();
    unsigned getVampiresLeft();
    unsigned getHumansLeft();
private:
    void fill();
    void generateVampires(unsigned amount);
    void generateHumans(unsigned amount);
    const unsigned HEIGHT;
    const unsigned WIDTH;
    const unsigned VAMPIRES;
    const unsigned HUMANS;
    unsigned humans;
    unsigned vampires;
    const char LEFT_RIGHT_LIMITERS = '|';
    const char TOP_BOTTOM_LIMITERS = '-';
    const char CORNER_LIMITERS = '+';

    unsigned int turn;
    std::list<std::shared_ptr<Humanoid>> humanoids;

    char **values;
    void clearDisplay();
    void initialiseDisplay();
};


#endif //LABO_04_FIELD_HPP
