#ifndef _MOVEMENT_H
#define _MOVEMENT_H

#include "../../lib/Vecteur.h"
#include "E_Direction.h"

class Movement {
protected:
    Vecteur moveTowards(DIRECTION direction, Vecteur position);
public:
    Movement() {}
    ~Movement() {}
    virtual Vecteur Move(Vecteur start, Vecteur objective);
};

#endif