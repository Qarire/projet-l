#include "PersoSorcerer.h"

#include <iostream>
using namespace std;


void PersoSorcerer::receiveDamage(int damage, bool isAttacked) {
    int pvInit = this->pv;
    if (isAttacked==true){
        pv-= damage*2;
    }
    else if (isAttacked == false && pv < pvInit) {
        pv+=damage*1.4;
    }
    if (pv>pvInit) 
        pv=pvInit;
    if(pv <= 0)
        kill();
}