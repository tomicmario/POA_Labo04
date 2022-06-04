//
// Created by mario on 04/06/2022.
//

#ifndef LABO_04_TRANSFORM_HPP
#define LABO_04_TRANSFORM_HPP

#include "Kill.hpp"


class Transform : public Kill {
public:
    explicit Transform(const std::shared_ptr<Humanoid>& humanoid);
    void execute(Field& field) override;
};


#endif //LABO_04_TRANSFORM_HPP
