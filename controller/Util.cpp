#include "Util.hpp"
#include <cmath>
#include <random>

double Util::getDistance(const std::shared_ptr<Humanoid>& h1, const std::shared_ptr<Humanoid>& h2) {
    unsigned x1 = h1->getX();
    unsigned y1 = h1->getY();
    unsigned x2 = h2->getX();
    unsigned y2 = h2->getY();
    return std::sqrt( (x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) );
}
unsigned Util::getRandomUnsigned(unsigned int min, unsigned int max) {
    static std::default_random_engine generator;

    std::uniform_int_distribution<unsigned> distribution(min,max - 1);
    return distribution(generator);
}