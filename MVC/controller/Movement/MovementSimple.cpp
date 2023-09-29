#include "MovementSimple.h"

#include <cstdlib>

Vecteur MovementSimple::Move(Vecteur start, Vecteur objective) {
    int diffX = objective.getX() - start.getX();
    int diffY = objective.getY() - start.getY();

    if(abs(diffX) > abs(diffY)) 
        return moveTowards((diffX > 0)? RIGHT : LEFT, start);
    else if (abs(diffX) < abs(diffY)) 
        return moveTowards((diffY > 0)? DOWN : UP, start);
    else if (abs(diffX) == abs(diffY) && abs(diffX) !=0)
        return moveTowards((diffX > 0)? RIGHT : LEFT, start);

    return start;
}