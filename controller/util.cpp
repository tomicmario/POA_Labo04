//
// Created by mario on 04/06/2022.
//

#include "util.hpp"
#include "cmath"
#include <random>

double util::getDistance(const std::shared_ptr<Humanoid>& h1, const std::shared_ptr<Humanoid>& h2) {
    return std::sqrt( (h2->getX() - h1->getX()) * (h2->getX() - h1->getX()) + (h2->getY() - h1->getY()) * (h2->getY() - h1->getY()) );
}
unsigned util::getRandomUnsigned(unsigned int min, unsigned int max) {
    static std::default_random_engine generator;

    std::uniform_int_distribution<unsigned> distribution(min,max - 1);
    return distribution(generator);
}