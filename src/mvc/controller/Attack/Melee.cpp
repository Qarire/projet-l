#include "Melee.h"


bool Melee::canTouch() {
    int diffX = abs(attacker->getPosition().x - target->getPosition().x);
    int diffY = abs(attacker->getPosition().y - target->getPosition().y);

    if(diffX <= 1 && diffY <= 1)
        return true;
    return false;
}

int Melee::damage() {

    return 20;
}

void Melee::Act() {
    int _damage = damage();
    bool verif_touch = canTouch();
    if(verif_touch) {
        target->changeHP(_damage, true);
    }
}