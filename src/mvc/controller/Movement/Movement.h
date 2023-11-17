#pragma once

#include "Position.h"
#include "E_Direction.h"
#include "Action.h"

class Movement : public Action {

    
protected:
    Position destination; 
    Position origin;
    
    Position moveTowards(DIRECTION direction, Position position);
    
public:
    Movement(Position destination, Position origin, float time, float cooldown = 0) : Action(time,cooldown) {};
    ~Movement() {};

    virtual Position Move() = 0;
};