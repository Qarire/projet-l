#include "AttackBouledeFeu.h"


bool AttackBouledeFeu::canTouch() {
    int diffX = abs(attacker->getPosition().x - target->getPosition().x);
    int diffY = abs(attacker->getPosition().y - target->getPosition().y);

    if(diffX <= 3 && diffY <= 3)
        return true;
    return false;
}

int AttackBouledeFeu::damage() {

    return 15;
}

void AttackBouledeFeu::Act() {
    
    Position pos = target->getPosition();
    vector<CharacterData*> listPerso;
    int _damage = damage();
    bool verif_touch = canTouch();
    
    if(verif_touch) {
        target->changeHP(_damage, true);
        listPerso = field->findAllCharacterData(pos,1);
        for(int i=0; i<listPerso.size(); i++){
            listPerso->changeHP(_damage, true);
        }
    }      
}