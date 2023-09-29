#pragma once

#include <vector>
#include "AttackData.h"
#include "Vecteur.h"
#include "Action.h"

class Attack {
private: 
    AttackData spell;

public:
    Attack() {}
    ~Attack() {}


    virtual bool canTouch(Vecteur myPosition, Vecteur targetPosition) = 0;
    virtual vector<Vecteur> findAllPositionWhereIcanHit(Vecteur targetPosition, int heightTerrain, int widthTerrain);
    virtual int damage(Vecteur myPosition, Vecteur targetPosition) = 0;
};