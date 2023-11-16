#pragma once 

#include <cmath>
#include "Attack.h"

class AttackBouledeFeu: public Attack {
public:
    AttackBouledeFeu(CharacterData* attacker, CharacterData* target) : Attack(attacker, target,1,0) {}
    ~AttackBouledeFeu() {}

    bool canTouch() override;
    int damage() override;
    void Act() override;
    
};