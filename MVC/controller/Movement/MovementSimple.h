#pragma once

#include "Movement.h"
#include "Action.h"

class MovementSimple : public Movement {
public:
    MovementSimple(int heightTerrain, int widthTerrain) : Movement(heightTerrain, widthTerrain) {}
    ~MovementSimple() {}
    Vecteur Move(Vecteur start, Vecteur objective) override;

};