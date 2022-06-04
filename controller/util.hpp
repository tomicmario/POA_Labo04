//
// Created by mario on 04/06/2022.
//

#ifndef LABO_04_UTIL_HPP
#define LABO_04_UTIL_HPP


#include "../humanoid/Humanoid.hpp"
#include <memory>

class util {
public:
    static double getDistance(const std::shared_ptr<Humanoid>& h1, const std::shared_ptr<Humanoid>& h2);
};


#endif //LABO_04_UTIL_HPP
