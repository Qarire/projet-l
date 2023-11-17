#include "Range.h"

bool Range::canTouch() {
    int diffX = abs(attacker->getPosition().x - target->getPosition().x);
    int diffY = abs(attacker->getPosition().y - target->getPosition().y);

    if(diffX >= 3 || diffY >=3)
        return true;
    return false;
}


int Range::damage() {
    int diffX = abs(attacker->getPosition().x - target->getPosition().x);
    int diffY = abs(attacker->getPosition().y - target->getPosition().y);

    int real_dist = diffX + diffY;

    if (real_dist <= 4) {
        return 5;
    } else if (real_dist = 6) {
        return 20;  
    }else 
        return 10;  
}

void Range::Act() {
    int _damage = damage();
    bool verif_touch = canTouch();
    if(verif_touch) {
        target->changeHP(_damage, true);
    }
}