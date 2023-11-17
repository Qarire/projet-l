#pragma once

#include <vector>
#include "AttackData.h"
#include "Action.h"

using namespace std;

class Attack : public Action{
protected: 
    CharacterData* target;
    CharacterData* attacker;
public:
   
    Attack(CharacterData* attacker,CharacterData* target, float time, float cooldown = 0) : Action(time,cooldown) {}
    ~Attack() {}

   
    virtual void Act() = 0;
    virtual bool canTouch() = 0;
    virtual int damage() = 0;
};