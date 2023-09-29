#include "Melee.h"


bool Melee::canTouch(Vecteur myPosition, Vecteur targetPosition) {
    int diffX = abs(myPosition.getX() - targetPosition.getX());
    int diffY = abs(myPosition.getY() - targetPosition.getY());

    if(diffX <= 1 && diffY <= 1)
        return true;
    return false;
}

int Melee::damage(Vecteur myPosition, Vecteur targetPosition) {

    return 20;
}