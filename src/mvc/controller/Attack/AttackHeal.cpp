#include "AttackHeal.h"

bool AttackHeal::canTouch() {
    int diffX = abs(attacker->getPosition().x - target->getPosition().x);
    int diffY = abs(attacker->getPosition().y - target->getPosition().y);

    if(diffX <= 3 && diffY <= 3)
        return true;
    return false;
}

int AttackHeal::damage() {

    return 10;
}

void AttackHeal::Act() {
    int _damage = damage();
    bool verif_touch = canTouch();
    if(verif_touch) {
        target->changeHP(_damage, false);
    }
}