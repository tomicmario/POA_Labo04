//
// Created by ylang on 12.05.2022.
//

#include "Humanoid.h"

Humanoid::Humanoid()
: id(staticId++)
{

}

void Humanoid::setPosition(){
    this.x = 0;
    this.y = 0;
}