#include "PersoSupport.h"

#include <iostream>
using namespace std;


void PersoSupport::receiveDamage(int damage, bool isAttacked) {
    int pvInit = this->pv;
    if (isAttacked==true){
        pv-= damage*1.5;
    }
    else if (isAttacked == false && pv < pvInit) {
        pv+=damage*1.2;
    }
    if (pv>pvInit) 
        pv=pvInit;
    if(pv <= 0)
        kill();
}