#include "MovementSimple.h"

#include <cstdlib>

Position MovementSimple::Move() {
    int diffX = destination.x - origin.x;
    int diffY = destination.y - origin.y;

    if(abs(diffX) > abs(diffY)) 
        return moveTowards((diffX > 0)? RIGHT : LEFT, origin);
    else if (abs(diffX) < abs(diffY)) 
        return moveTowards((diffY > 0)? DOWN : UP, origin);
    else if (abs(diffX) == abs(diffY) && abs(diffX) !=0)
        return moveTowards((diffX > 0)? RIGHT : LEFT, origin);

    return origin;
}