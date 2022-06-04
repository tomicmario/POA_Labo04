//
// Created by ylang on 12.05.2022.
//

#include "Field.hpp"
#include "../controller/util.hpp"
#include "../humanoid/Human.hpp"
#include "../humanoid/Vampire.hpp"
#include "../humanoid/Buffy.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>

using namespace std;

Field::Field(unsigned height, unsigned width, unsigned humans, unsigned vampires)
: HEIGHT(height), WIDTH(width), HUMANS(humans), VAMPIRES(vampires), values(nullptr) {
    initialise();
}

Field::~Field(){
    clearDisplay();
}

void Field::fill() {
    initialiseDisplay();
    for(size_t i  = 0; i < HEIGHT; ++i){
        for(size_t j = 0; j < WIDTH; ++j){
                values[i][j] = ' ';
        }
    }

    for(auto it = humanoids.begin(); it != humanoids.end(); ++it){
        unsigned x = it->get()->getX();
        unsigned y = it->get()->getY();
        values[x][y] = it->get()->getSymbol();
    }
}
void Field::display(){
    fill();
    cout << CORNER_LIMITERS << std::setfill (TOP_BOTTOM_LIMITERS) << std::setw (WIDTH + 1) << CORNER_LIMITERS << std::endl;
    for(size_t i = 0; i < HEIGHT; ++i){
        cout << LEFT_RIGHT_LIMITERS;
        for(size_t j = 0; j < WIDTH; ++j){
            cout << values[i][j];
        }
        cout << LEFT_RIGHT_LIMITERS;
        cout << endl;
    }
    cout << CORNER_LIMITERS << std::setfill (TOP_BOTTOM_LIMITERS) << std::setw (WIDTH + 1) << CORNER_LIMITERS << std::endl;
}

void Field::update() const{

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


std::shared_ptr<Humanoid> Field::findNearestHuman(const shared_ptr<Humanoid>& searcher) const {
    std::function<bool (const std::shared_ptr<Humanoid>)> isHuman= [](const std::shared_ptr<Humanoid>& humanoid) {
        return dynamic_cast<Human*>(humanoid.get()) != nullptr;
    };
    return nearestX(searcher,isHuman);
    /*
    std::shared_ptr<Humanoid> closestHuman;
    double distance = HEIGHT * WIDTH;
    for (const std::shared_ptr<Humanoid>& it : humanoids) {
        if (dynamic_cast<Human*>(it.get()) != nullptr) {
            std::shared_ptr<Humanoid> currentClosest(it);
            cout << it.use_count() << endl;
            double currentDistance = util::getDistance(currentClosest, searcher);
            if(currentDistance < distance){
                closestHuman = currentClosest;
                distance = currentDistance;
                cout << it.use_count() << endl;
            }
        }
    }
    return closestHuman;
    */
}

std::shared_ptr<Humanoid> Field::findNearestVampire(const shared_ptr<Humanoid>& searcher) const {
    std::function<bool (const std::shared_ptr<Humanoid>)> isVampire= [](const std::shared_ptr<Humanoid>& humanoid) {
        return dynamic_cast<Vampire*>(humanoid.get()) != nullptr;
    };
    return nearestX(searcher,isVampire);
}

void Field::generateVampires(unsigned amount) {
    for(unsigned i = 0; i < amount; ++i){
        unsigned x = util::getRandomUnsigned(0, WIDTH);
        unsigned y = util::getRandomUnsigned(0, HEIGHT);
        humanoids.push_back(std::make_shared<Vampire>(x, y));
        vampires++;
    }
}

void Field::generateHumans(unsigned amount) {
    for(unsigned i = 0; i < amount; ++i){
        unsigned x = util::getRandomUnsigned(0, WIDTH);
        unsigned y = util::getRandomUnsigned(0, HEIGHT);
        humanoids.push_back(std::make_shared<Human>(x, y));
        humans++;
    }
}

void Field::generateBuffy() {
    unsigned x = util::getRandomUnsigned(0, WIDTH);
    unsigned y = util::getRandomUnsigned(0, HEIGHT);
    humanoids.push_back(std::make_shared<Buffy>(x, y));
}

void Field::initialise() {
    humanoids.clear();
    vampires = 0;
    humans = 0;
    turn = 0;
    generateVampires(2);//VAMPIRES);
    generateHumans(10);//HUMANS);
    generateBuffy();
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

unsigned Field::getVampiresLeft() {
    return vampires;
}

unsigned Field::getHumansLeft() {
    return humans;
}

std::shared_ptr<Humanoid>
Field::nearestX(const shared_ptr<Humanoid>& searcher, function<bool (shared_ptr<Humanoid>)> func) const {
    std::shared_ptr<Humanoid> closestHuman;
    double distance = HEIGHT * WIDTH;
    for (const std::shared_ptr<Humanoid>& it : humanoids) {
        if (func(it)) {
            std::shared_ptr<Humanoid> currentClosest(it);
            double currentDistance = util::getDistance(currentClosest, searcher);
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





