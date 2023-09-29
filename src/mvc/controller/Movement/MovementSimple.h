#pragma once

#include "Movement.h"
#include "Action.h"

class MovementSimple : public Movement {
public:
    MovementSimple(int heightTerrain, int widthTerrain) : Movement(heightTerrain, widthTerrain) {}
    ~MovementSimple() {}
    Position Move(Position start, Position objective) override;

};