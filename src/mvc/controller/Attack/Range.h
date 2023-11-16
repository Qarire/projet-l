#pragma once 

#include <cmath>
#include "Attack.h"

class Range: public Attack {
public:
    Range(CharacterData* attacker, CharacterData* target) : Attack(attacker, target,1,0) {}
    ~Range() {}

    bool canTouch() override;
    int damage() override;
    void Act() override;
  
};