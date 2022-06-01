//
// Created by ylang on 12.05.2022.
//

#include "Field.h"
#include <iostream>
#include <iomanip>

using namespace std;

Field::Field(unsigned int height, unsigned int width)
:   height(height), width(width)
{

}

void Field::display() const{
    cout << CORNER_LIMITERS << setfill(TOP_BOTTOM_LIMITERS) << setw(width-2) << CORNER_LIMITERS << endl;
    for(size_t i = 0; i < height; ++i){
        cout << LEFT_RIGHT_LIMITERS << setfill(' ') << setw(width-2) << LEFT_RIGHT_LIMITERS << endl;
    }
    cout << CORNER_LIMITERS << setfill(TOP_BOTTOM_LIMITERS) << setw(width-2) << CORNER_LIMITERS << endl;
}

void Field::update() const{

}

int Field::nextTurn()
{
    // Déterminer les prochaines actions
    for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->setAction(*this);
    // Executer les actions
    for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
        (*it)->executeAction(*this);
    // Enlever les humanoides tués
    for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); )
        if (!(*it)->isAlive()) {
            it = humanoids.erase(it); // suppression de l’élément dans la liste
            delete *it; // destruction de l’humanoide référencé
        }
        else
            ++it;
    return turn++;
}
