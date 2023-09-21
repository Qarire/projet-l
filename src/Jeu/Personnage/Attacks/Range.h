#pragma once 

#include <cmath>
#include "Attack.h"

class Range: public Attack {
public:
    Range() : Attack() {}
    ~Range() {}

    bool canTouch(Vecteur myPosition, Vecteur targetPosition) override;
    int damage(Vecteur myPosition, Vecteur targetPosition) override;
};