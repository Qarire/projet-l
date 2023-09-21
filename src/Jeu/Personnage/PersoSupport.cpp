#include "PersoSupport.h"

#include <iostream>
using namespace std;

PersoSupport::PersoSupport(position, pv) : Personnage(position, pv, new Range(), new MovementSimple()) {
    this->pv = pv*2;
}

void PersoSupport::receiveDamage(int damage) {
    pv-= damage*1.5;

    if(pv <= 0)
        kill();
}