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
    CharacterData(Team team, Stats stats, Position position, float healModifier, float damageModifier, Type type, Type favoriteEnemyType);

    Position getPosition() const {return this->position; };
    void setPosition(Position position) {this->position = position; };

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

class CharacterDataTank : public CharacterData {
public:
    CharacterDataTank(Team team, Position position)
    : CharacterData(team, Stats(500, 5, 20), position, 1, 1, Tank, Tank) {};
};
class CharacterDataMelee : public CharacterData {
public:
    CharacterDataMelee(Team team, Position position)
    : CharacterData(team, Stats(300, 20, 10), position, 1, 1, Melee, Tank) {};
};
class CharacterDataArcher : public CharacterData {
public:
    CharacterDataArcher(Team team, Position position)
    : CharacterData(team, Stats(300, 20, 5), position, 1, 1, Archer, Tank) {};
};
class CharacterDataSorcerer : public CharacterData {
public:
    CharacterDataSorcerer(Team team, Position position)
    : CharacterData(team, Stats(300, 20, 5), position, 1, 1, Sorcerer, Tank) {};
};
class CharacterDataHealer : public CharacterData {
public:
    CharacterDataHealer(Team team, Position position)
    : CharacterData(team, Stats(100, 10, 10), position, 1, 1, Healer, Tank) {};
};