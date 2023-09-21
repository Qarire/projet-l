#pragma once

#include <vector>

#include "Terrain.h"
#include "vecteur.h"

class Attack {
private:


public:
    Attack() {}
    ~Attack() {}


    virtual bool canTouch(Vecteur myPosition, Vecteur targetPosition) = 0;
    virtual vector<Vecteur> findAllPositionWhereIcanHit(Vecteur targetPosition) = 0;
    virtual int damage(Vecteur myPosition, Vecteur targetPosition) = 0;
};