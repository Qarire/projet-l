#include "PersoTank.h"

#include <iostream>
using namespace std;

PersoTank::PersoTank(position, pv) : Personnage(position, pv, new Melee(), new MovementSimple()) {
    this->pv = pv*2;
}

void PersoTank::receiveDamage(int damage) {
    pv-= damage/2;

    if(pv <= 0)
        kill();
}