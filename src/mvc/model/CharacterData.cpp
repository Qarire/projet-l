#include "CharacterData.h"

using namespace std;

CharacterData::CharacterData(Team team, Stats stats, float healModifier, float damageModifier, Type type, Type favoriteEnemyType) {
    this->team = team;
    this->stats = stats;
    this->healModifier = healModifier;
    this->damageModifier = damageModifier;
    this->type = type;
    this->favoriteEnemyType = favoriteEnemyType;
}

void CharacterData::changeHP(int value, bool isDamaged) {
    
    if (isDamaged==true){
        stats.hp.Value-= value;
    }
    else if (isDamaged == false && stats.hp.Value < stats.hp.Max) {
        stats.hp.Value+=value;
    }
    if (stats.hp.Value>stats.hp.Max) 
        stats.hp.Value=stats.hp.Max;
    if(stats.hp.Value <= 0)
        kill();

}