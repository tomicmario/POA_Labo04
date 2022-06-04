//
// Created by ylang on 12.05.2022.
//

#include "Field.hpp"
#include "../controller/util.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

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

int Field::nextTurn()
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
            std::shared_ptr<Human> current(dynamic_cast<Human*>(it->get()));
            if(current != nullptr){
                humans--;
            }
            else {
                vampires--;
            }

            it = humanoids.erase(it); // suppression de l’élément dans la liste

        }
        else
            ++it;
    return turn++;
}


std::shared_ptr<Human> Field::findNearestHuman(const shared_ptr<Humanoid>& searcher) const {
    std::shared_ptr<Human> closestHuman = nullptr;
    double distance = HEIGHT * WIDTH;
    for (auto it = humanoids.begin(); it != humanoids.end(); it++) {
        std::shared_ptr<Human> currentClosestHuman(dynamic_cast<Human*>(it->get()));
        if (currentClosestHuman != nullptr) {
            double currentDistance = util::getDistance(currentClosestHuman, searcher);
            if(currentDistance < distance){
                closestHuman = currentClosestHuman;
                distance = currentDistance;
            }
        }
    }
    return closestHuman;
}

std::shared_ptr<Vampire> Field::findNearestVampire(const shared_ptr<Humanoid>& searcher) const{
    std::shared_ptr<Vampire> closestVampire = nullptr;
    double distance = HEIGHT * WIDTH;
    for (auto it = humanoids.begin(); it != humanoids.end(); it++) {
        std::shared_ptr<Vampire> currentClosestVampire(dynamic_cast<Vampire*>(it->get()));
        if (currentClosestVampire != nullptr) {
            double currentDistance = util::getDistance(currentClosestVampire, searcher);
            if(currentDistance < distance){
                closestVampire = currentClosestVampire;
                distance = currentDistance;
            }
        }
    }
    return closestVampire;
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

void Field::initialise() {
    humanoids.clear();
    vampires = 0;
    humans = 0;
    generateHumans(1);//HUMANS);
    generateVampires(1);//VAMPIRES);
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


