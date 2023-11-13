#pragma once 

#include <cmath>
#include "Attack.h"

class AttackBouledeFeu: public Attack {
public:
    AttackBouledeFeu() : Attack() {}
    ~AttackBouledeFeu() {}

    bool canTouch() override;
    int damage() override;
    void Act() override;
    //vector<Position> findAllPositionWhereIcanHit(int heightTerrain, int widthTerrain) override;
};