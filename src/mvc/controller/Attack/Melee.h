#pragma once 

#include <cmath>
#include "Attack.h"

class Melee: public Attack {
public:
    Melee(CharacterData* attacker, CharacterData* target) : Attack(attacker, target,1,0)  {}
    ~Melee() {}

    bool canTouch() override;
    int damage() override;
    void Act() override;
  
};