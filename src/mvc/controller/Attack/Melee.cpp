#include "Melee.h"


bool Melee::canTouch(Position myPosition, Position targetPosition) {
    int diffX = abs(myPosition.x - targetPosition.x);
    int diffY = abs(myPosition.y - targetPosition.y);

    if(diffX <= 1 && diffY <= 1)
        return true;
    return false;
}

int Melee::damage(Position myPosition, Position targetPosition) {

    return 20;
}