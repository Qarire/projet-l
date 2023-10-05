#include "MovementSimple.h"

#include <cstdlib>

Position MovementSimple::Move(Position start, Position objective) {
    int diffX = objective.x - start.x;
    int diffY = objective.y - start.y;

    if(abs(diffX) > abs(diffY)) 
        return moveTowards((diffX > 0)? RIGHT : LEFT, start);
    else if (abs(diffX) < abs(diffY)) 
        return moveTowards((diffY > 0)? DOWN : UP, start);
    else if (abs(diffX) == abs(diffY) && abs(diffX) !=0)
        return moveTowards((diffX > 0)? RIGHT : LEFT, start);

    return start;
}