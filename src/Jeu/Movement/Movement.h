#pragma once

#include "Vecteur.h"
#include "E_Direction.h"


class Movement {
protected:
    Vecteur moveTowards(DIRECTION direction, Vecteur position);
    
public:
    Movement() {}
    ~Movement() {}
    virtual Vecteur Move(Vecteur start, Vecteur objective);
};