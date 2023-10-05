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
        Type favoriteEnemyType;
    public :
    CharacterData(Team team, Stats stats, float healModifier, float damageModifier, Type type, Type favoriteEnemyType);

    Position getPos() const {return this->position; };
    void setPos(Position pos) {this->position = pos; };

    Stats getStats() const {return stats;};
    Team getTeam() const {return team;};
    float getHealModifier() const {return this->healModifier; };
    float getDmgModifier () const {return this->damageModifier; };
    bool getisDead() const { return isDead; };
    Type getType() const {return type;};
    Type getFavoriteEnemyType() const {return favoriteEnemyType;};

    void changeHP(int value, bool isDamaged);
    void kill() { isDead = true; };
};