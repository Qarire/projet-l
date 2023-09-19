#include "MovementSimple.h"


Vecteur MovementSimple::Move(Vecteur start, Vecteur objective) {
    int diffX = objective.getX() - start.getY();
    int diffY = objective.getY() - start.getY();

    if(diffX >= diffY) 
        return moveTowards((diffX > 0)? RIGHT : LEFT, start);
    else
        return moveTowards((diffY > 0)? DOWN : UP, start);

    return start;
}