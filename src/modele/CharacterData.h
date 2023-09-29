#pragma once
#include <iostream>
#include "Stats.h"
#include "Position.h"
#include "Team.h"
#include "Type.h"

using namespace std;
class CharacterData {
    private :
        Position position;
        bool isDead;
        float healModifier = 1;
        float damageModifier = 1;
        Team team;
        Stats stats;
        Type type;
    public :
    CharacterData(Team TEAM, Stats stats, float healModifier, float damageModifier, Type type);
    Position getPos() const {return this->position; };
    void setPos(Position pos) {this->position = pos; };
    Stats getStats(){return stats;};
    float getHealModifier() const {return this->healModifier; };
    float getDmgModifier () const {return this->damageModifier; };
    virtual void changeHP(int value, bool isDamaged);
    bool getisDead() const { return isDead; };
    void kill() { isDead = true; };
};