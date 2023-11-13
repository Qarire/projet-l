#pragma once

#include <vector>
#include "AttackData.h"

#include "CharacterData.h"

using namespace std;

class Attack {
protected: 
    AttackData spell;
    CharacterData* target;
    CharacterData* attacker;
public:
    Attack () {}
    Attack(CharacterData* attacker,CharacterData* target) {}
    ~Attack() {}

    virtual void Act() = 0;
    virtual bool canTouch() = 0;
    virtual vector<Position> findAllPositionWhereIcanHit(int heightTerrain, int widthTerrain) = 0;
    virtual int damage() = 0;
};