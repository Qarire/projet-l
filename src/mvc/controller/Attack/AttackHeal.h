#pragma once 

#include <cmath>
#include "Attack.h"

class AttackHeal: public Attack {
public:
    AttackHeal(CharacterData* attacker, CharacterData* target) : Attack(attacker, target,1,0) {}
    ~AttackHeal() {}

    bool canTouch() override;
    int damage() override;
    void Act() override;
};