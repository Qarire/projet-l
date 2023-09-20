#pragma once

#include "Movement.h"

class MovementSimple : public Movement {
public:
    MovementSimple() : Movement() {}
    ~MovementSimple() {}
    Vecteur Move(Vecteur start, Vecteur objective) override;

};