#include "Field.hpp"
#include "Util.hpp"
#include "../humanoid/Human.hpp"
#include "../humanoid/Vampire.hpp"
#include "../humanoid/Buffy.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>


Field::Field(unsigned height, unsigned width, unsigned humans, unsigned vampires)
: HEIGHT(height), WIDTH(width), HUMANS(humans), VAMPIRES(vampires), values(nullptr) {
    initialiseDisplay();
    initialise();
}

Field::~Field(){
    clearDisplay();
}

unsigned Field::nextTurn()
{
    // Déterminer les prochaines actions
    for (auto it = humanoids.begin(); it != humanoids.end(); it++)
        it->get()->setAction(*this);
    // Executer les actions
    for (auto it = humanoids.begin(); it != humanoids.end(); it++)
        it->get()->executeAction(*this);
    // Enlever les humanoides tués
    for (auto it = humanoids.begin(); it != humanoids.end(); )
        if (!it->get()->isAlive()) {
            it = humanoids.erase(it); // suppression de l’élément dans la liste
        }
        else
            ++it;
    return ++turn;
}


std::shared_ptr<Humanoid> Field::findNearestHuman(const std::shared_ptr<Humanoid>& searcher) const {
    std::function<bool (const std::shared_ptr<Humanoid>)> isHuman = [](const std::shared_ptr<Humanoid>& humanoid) {
        return dynamic_cast<Human*>(humanoid.get()) != nullptr;
    };
    return nearestX(searcher,isHuman);
}

std::shared_ptr<Humanoid> Field::findNearestVampire(const std::shared_ptr<Humanoid>& searcher) const {
    std::function<bool (const std::shared_ptr<Humanoid>)> isVampire= [](const std::shared_ptr<Humanoid>& humanoid) {
        return dynamic_cast<Vampire*>(humanoid.get()) != nullptr;
    };
    return nearestX(searcher,isVampire);
}

void Field::generateVampires(unsigned amount) {
    for(unsigned i = 0; i < amount; ++i){
        unsigned x = Util::getRandomUnsigned(0, WIDTH);
        unsigned y = Util::getRandomUnsigned(0, HEIGHT);
        humanoids.push_back(std::make_shared<Vampire>(x, y));
        vampires++;
    }
}

void Field::generateHumans(unsigned amount) {
    for(unsigned i = 0; i < amount; ++i){
        unsigned x = Util::getRandomUnsigned(0, WIDTH);
        unsigned y = Util::getRandomUnsigned(0, HEIGHT);
        humanoids.push_back(std::make_shared<Human>(x, y));
        humans++;
    }
}

void Field::generateBuffy() {
    unsigned x = Util::getRandomUnsigned(0, WIDTH);
    unsigned y = Util::getRandomUnsigned(0, HEIGHT);
    humanoids.push_back(std::make_shared<Buffy>(x, y));
}

void Field::initialise() {
    humanoids.clear();
    vampires = 0;
    humans = 0;
    turn = 0;
    generateVampires(VAMPIRES);
    generateHumans(HUMANS);
    generateBuffy();
}

unsigned Field::getVampiresLeft() const {
    return vampires;
}

unsigned Field::getHumansLeft() const {
    return humans;
}

std::shared_ptr<Humanoid>
Field::nearestX(const std::shared_ptr<Humanoid>& searcher, std::function<bool (std::shared_ptr<Humanoid>)> func) const {
    std::shared_ptr<Humanoid> closestHuman;
    double distance = HEIGHT * WIDTH; // the distance can't be bigger than this
    for (const std::shared_ptr<Humanoid>& it : humanoids) {

        // If the humanoid is of X type, then we check the distance and keep it if it's closer
        if (func(it)) {
            std::shared_ptr<Humanoid> currentClosest(it);
            double currentDistance = Util::getDistance(currentClosest, searcher);
            if(currentDistance < distance){
                closestHuman = currentClosest;
                distance = currentDistance;
            }
        }
    }
    return closestHuman;
}

unsigned Field::getWidth() const {
    return WIDTH;
}

unsigned Field::getHeight() const {
    return HEIGHT;
}

void Field::humanKilled() {
    humans--;
}

void Field::vampireKilled() {
    vampires--;
}

void Field::addVampire(unsigned x, unsigned y) {
    humanoids.push_back(std::make_shared<Vampire>(x, y));
    vampires++;
}

void Field::displayTopBottom() const {
    std::cout << CORNER_LIMITERS << std::setfill (TOP_BOTTOM_LIMITERS)
              << std::setw (WIDTH + 1) << CORNER_LIMITERS << std::endl;
}

void Field::fill() const {
    for(size_t i  = 0; i < HEIGHT; ++i){
        for(size_t j = 0; j < WIDTH; ++j){
            values[i][j] = ' ';
        }
    }
}

void Field::setHumanoidsDisplay() const {
    fill();
    for(auto it = humanoids.begin(); it != humanoids.end(); ++it){
        unsigned x = it->get()->getX();
        unsigned y = it->get()->getY();
        values[x][y] = it->get()->getSymbol();
    }
}


void Field::display() const {
    setHumanoidsDisplay();
    displayTopBottom();
    for(size_t i = 0; i < HEIGHT; ++i){
        std::cout << LEFT_RIGHT_LIMITERS;
        for(size_t j = 0; j < WIDTH; ++j){
            std::cout << values[i][j];
        }
        std::cout << LEFT_RIGHT_LIMITERS << std::endl;
    }
    displayTopBottom();
}

void Field::clearDisplay() {
    if(values != nullptr) {
        for (size_t i = 0; i < HEIGHT; ++i) {
            delete values[i];
        }
        delete[] values;
    }
}

void Field::initialiseDisplay() {
    clearDisplay();
    values = new char*[HEIGHT];
    for(size_t i = 0; i < HEIGHT; ++i){
        values[i] = new char[WIDTH];
    }
}

