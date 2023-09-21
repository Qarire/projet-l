#include "PersoSorcerer.h"

#include <iostream>
using namespace std;


void PersoSorcerer::receiveDamage(int damage) {
    pv-= damage*2;

    if(pv <= 0)
        kill();
}