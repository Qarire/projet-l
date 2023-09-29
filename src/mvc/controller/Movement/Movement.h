#pragma once

#include "Position.h"
#include "E_Direction.h"
#include "Action.h"

class Movement {
private:
    int heightTerrain;
    int widthTerrain;

protected:
    Position moveTowards(DIRECTION direction, Position position);
    
public:
    Movement(int heightTerrain, int widthTerrain) { this->heightTerrain = heightTerrain; this->widthTerrain = widthTerrain; }
    ~Movement() {}

    int getHeight() const { return heightTerrain; }
    int getWidth() const { return widthTerrain; }

    virtual Position Move(Position start, Position objective);
};