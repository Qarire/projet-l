#pragma once

#include "Movement.h"

class MovementSimple : public Movement {
public:
    MovementSimple(int heightTerrain, int widthTerrain) : Movement(heightTerrain, widthTerrain) {}
    ~MovementSimple() {}
    Vecteur Move(Vecteur start, Vecteur objective) override;

};