#include "PersoTank.h"

#include <iostream>
using namespace std;


void PersoTank::receiveDamage(int damage) {
    pv-= damage/2;

    if(pv <= 0)
        kill();
}