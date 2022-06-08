#ifndef LABO_04_UTIL_HPP
#define LABO_04_UTIL_HPP

#include "../humanoid/Humanoid.hpp"
#include <memory>

/**
 * Small class offering functions that are used throughout the program
 */
class Util {
public:

    /**
     * Returns the distance between two humanoids
     * @param h1 humanoid 1
     * @param h2 humanoid 2
     * @return Distance between two humanoids
     */
    static double getDistance(const std::shared_ptr<Humanoid>& h1, const std::shared_ptr<Humanoid>& h2);

    /**
     * Returns a number in [min, max[
     * @param min Lower bound
     * @param max Upper bound
     * @return Randomly generated number
     */
    static unsigned getRandomUnsigned(unsigned min, unsigned max);


    /**
     * Disabled constructor, copy constructor and = operator
     */
    Util() = delete;
    Util(const Util& other) = delete;
    Util& operator=(const Util& other) = delete;
};


#endif //LABO_04_UTIL_HPP
