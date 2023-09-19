#ifndef _MOVEMENTSIMPLE_H
#define _MOVEMENTSIMPLE_H

#include "Movement.h"

class MovementSimple : public Movement {
public:
    MovementSimple() : Movement() {}
    ~MovementSimple() {}
    Vecteur Move(Vecteur start, Vecteur objective) override;

};

#endif