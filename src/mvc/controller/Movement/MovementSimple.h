#pragma once

#include "Movement.h"
#include "Action.h"

class MovementSimple : public Movement {
public:
    MovementSimple(Position origin, Position destination) : Movement(origin, destination,1,0) {}
    ~MovementSimple() {}
    Position Move() override;

};