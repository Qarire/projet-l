#pragma once

#include <cmath>
#include "Attack.h"


class Melee : public Attack {
public:
    Melee() : Attack() {}
    ~Melee() {}


    bool canTouch(Vecteur myPosition, Vecteur targetPosition) override;
    vector<Vecteur> findAllPositionWhereIcanHit(Vecteur targetPosition) override;
    int damage(Vecteur myPosition, Vecteur targetPosition) override;
};