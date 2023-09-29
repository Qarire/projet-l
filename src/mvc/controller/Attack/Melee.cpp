#include "Melee.h"


bool Melee::canTouch(Position myPosition, Position targetPosition) {
    int diffX = abs(myPosition.getX() - targetPosition.getX());
    int diffY = abs(myPosition.getY() - targetPosition.getY());

    if(diffX <= 1 && diffY <= 1)
        return true;
    return false;
}

int Melee::damage(Position myPosition, Position targetPosition) {

    return 20;
}