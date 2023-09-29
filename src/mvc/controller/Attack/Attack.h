#pragma once

#include <vector>
#include "AttackData.h"
#include "Position.h"
#include "Action.h"

using namespace std;

class Attack {
private: 
    AttackData spell;

public:
    Attack() {}
    ~Attack() {}


    virtual bool canTouch(Position myPosition, Position targetPosition) = 0;
    virtual vector<Position> findAllPositionWhereIcanHit(Position targetPosition, int heightTerrain, int widthTerrain);
    virtual int damage(Position myPosition, Position targetPosition) = 0;
};