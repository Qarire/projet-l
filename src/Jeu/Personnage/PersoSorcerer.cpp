#include "PersoSorcerer.h"

#include <iostream>
using namespace std;

PersoTank::PersoTank(position, pv) : Personnage(position, pv, new Range(), new MovementSimple()) {
    this->pv = pv/1.5;
}

void PersoTank::receiveDamage(int damage) {
    pv-= damage*2;

    if(pv <= 0)
        kill();
}