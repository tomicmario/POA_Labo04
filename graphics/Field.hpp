#ifndef LABO_04_FIELD_HPP
#define LABO_04_FIELD_HPP


#include <list>
#include <memory>
#include <functional>

#include "../humanoid/Humanoid.hpp"
#include "../humanoid/Human.hpp"
#include "../humanoid/Vampire.hpp"

class Field {
public:
    Field(unsigned height, unsigned width, unsigned humans, unsigned vampires);
    ~Field();
    void display();
    void update() const;
    unsigned nextTurn();
    std::shared_ptr<Humanoid> findNearestHuman(const std::shared_ptr<Humanoid>& searcher) const;
    std::shared_ptr<Humanoid> findNearestVampire(const std::shared_ptr<Humanoid>& searcher) const;
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

    std::shared_ptr<Humanoid>
    nearestX(const std::shared_ptr<Humanoid> &searcher, std::function<bool(std::shared_ptr<Humanoid>)> func) const;
};


#endif //LABO_04_FIELD_HPP
