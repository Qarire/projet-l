#pragma once 

#include <cmath>
#include "Attack.h"

class Range: public Attack {
public:
    Range() : Attack() {}
    ~Range() {}

    bool canTouch(Position myPosition, Position targetPosition) override;
    int damage(Position myPosition, Position targetPosition) override;
};