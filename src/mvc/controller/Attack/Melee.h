#pragma once

#include <cmath>
#include "Attack.h"


class Melee : public Attack {
public:
    Melee() : Attack() {}
    ~Melee() {}


    bool canTouch(Position myPosition, Position targetPosition) override;
    int damage(Position myPosition, Position targetPosition) override;
};