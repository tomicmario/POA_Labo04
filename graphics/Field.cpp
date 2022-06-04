//
// Created by ylang on 12.05.2022.
//

#include "Field.hpp"
#include "../humanoid/Human.hpp"
#include "../humanoid/Vampire.hpp"
#include "../controller/util.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Field::Field(unsigned height, unsigned width, unsigned humans, unsigned vampires)
:   height(height), width(width), humans(humans), vampires(vampires), values(nullptr) {
    generateVampires(vampires);
    generateHumans(humans);
}

Field::~Field(){
    clearDisplay();
}

void Field::fill() {
    initialiseDisplay();
    for(size_t i  = 0; i < height; ++i){
        for(size_t j = 0; j < width; ++j){
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
    cout << CORNER_LIMITERS << std::setfill (TOP_BOTTOM_LIMITERS) << std::setw (width) << CORNER_LIMITERS << std::endl;
    for(size_t i = 0; i < height; ++i){
        cout << LEFT_RIGHT_LIMITERS;
        for(size_t j = 0; j < width; ++j){
            cout << values[i][j];
        }
        cout << LEFT_RIGHT_LIMITERS;
        cout << endl;
    }
    cout << CORNER_LIMITERS << std::setfill (TOP_BOTTOM_LIMITERS) << std::setw (width) << CORNER_LIMITERS << std::endl;
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
            it = humanoids.erase(it); // suppression de l’élément dans la liste
        }
        else
            ++it;
    return turn++;
}


std::shared_ptr<Human> Field::findNearestHuman(const shared_ptr<Humanoid>& searcher) {
    std::shared_ptr<Human> closestHuman = nullptr;
    double distance = height * width;
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

std::shared_ptr<Vampire> Field::findNearestVampire(const shared_ptr<Humanoid>& searcher) {
    std::shared_ptr<Vampire> closestVampire = nullptr;
    double distance = height * width;
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
        unsigned x = util::getRandomUnsigned(0, width);
        unsigned y = util::getRandomUnsigned(0, height);
        humanoids.push_back(std::make_shared<Vampire>(x, y));
    }
}

void Field::generateHumans(unsigned amount) {
    for(unsigned i = 0; i < amount; ++i){
        unsigned x = util::getRandomUnsigned(0, width);
        unsigned y = util::getRandomUnsigned(0, height);
        humanoids.push_back(std::make_shared<Human>(x, y));
    }
}

void Field::initialise() {
    generateHumans(humans);
    generateVampires(vampires);
}

void Field::clearDisplay() {
    if(values != nullptr) {
        for (size_t i = 0; i < height; ++i) {
            delete values[i];
        }
        delete[] values;
    }
}

void Field::initialiseDisplay() {
    clearDisplay();
    values = new char*[height];
    for(size_t i = 0; i < height; ++i){
        values[i] = new char[width];
    }
}


