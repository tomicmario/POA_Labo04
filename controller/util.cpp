//
// Created by mario on 04/06/2022.
//

#include "util.hpp"
#include "cmath"

double util::getDistance(const std::shared_ptr<Humanoid>& h1, const std::shared_ptr<Humanoid>& h2) {
    return std::sqrt( (h2->getX() - h1->getX()) * (h2->getX() - h1->getX()) + (h2->getY() - h1->getY()) * (h2->getY() - h1->getY()) );
}
