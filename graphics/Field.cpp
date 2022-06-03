//
// Created by ylang on 12.05.2022.
//

#include "Field.hpp"
#include "../humanoid/Human.hpp"
#include "../humanoid/Vampire.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

Field::Field(unsigned int height, unsigned int width)
:   height(height), width(width)
{
    values = new char*[height];
    for(size_t i = 0; i < height; ++i){
        values[i] = new char[width];
    }
}
Field::~Field(){
    if(values != nullptr) {
        for (size_t i = 0; i < height; ++i) {
            delete values[i];
        }
        delete[] values;
    }
}
void Field::fill() const{
    for(size_t i  = 0; i < height; ++i){
        for(size_t j = 0; j < width; ++j){
            if(i == 0 && j == 0 || i == 0 && j == width-1 ||
            i == height-1 && j == 0 || i == height-1 && j == width-1){
                values[i][j] = '+';
            }
            else if(i == 0 || i == height-1){
                values[i][j] = '=';
            }
            else if(j == 0 || j == width-1){
                values[i][j] = '|';
            }
            else {
                values[i][j] = ' ';
            }

        }
    }
}
void Field::display() const{

    for(size_t i = 0; i < height; ++i){
        for(size_t j = 0; j < width; ++j){
            cout << values[i][j];
        }
        cout << endl;
    }
    /*cout << CORNER_LIMITERS << setfill(TOP_BOTTOM_LIMITERS) << setw(width-2) << CORNER_LIMITERS << endl;
    for(size_t i = 0; i < height; ++i){
        cout << LEFT_RIGHT_LIMITERS << setfill(' ') << setw(width-2) << LEFT_RIGHT_LIMITERS << endl;
    }
    cout << CORNER_LIMITERS << setfill(TOP_BOTTOM_LIMITERS) << setw(width-2) << CORNER_LIMITERS << endl;*/
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

/*
std::shared_ptr<Human> Field::findNearestHuman(const shared_ptr<Humanoid>& searcher) {
    std::shared_ptr<Human> closestHuman = nullptr;
    double distance = height * width;
    for (auto it = humanoids.begin(); it != humanoids.end(); it++) {
        std::shared_ptr<Human> currentClosestHuman(dynamic_cast<Human*>(it->get()));
        if (currentClosestHuman != nullptr) {
            double currentDistance = getDistance(searcher->getX(), searcher->getY(), (*it)->getX(), (*it)->getY());
            if(currentDistance < distance){
                closestHuman = currentClosestHuman;
                distance = currentDistance;
            }
        }
    }
    return closestHuman;
}
*/


double Field::getDistance(unsigned x1, unsigned y1, unsigned x2, unsigned y2) {
    return std::sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) );
}
