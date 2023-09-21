#include "PersoSupport.h"

#include <iostream>
using namespace std;


void PersoSupport::receiveDamage(int damage) {
    pv-= damage*1.5;

    if(pv <= 0)
        kill();
}