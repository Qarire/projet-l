#pragma once 

#include <cmath>
#include "Attack.h"

class AttackHeal: public Attack {
public:
    AttackHeal() : Attack() {}
    ~AttackHeal() {}

    bool canTouch() override;
    int damage() override;
    void Act() override;
};