#pragma once




#include "E_Direction.h"
#include "Vecteur.h"

class Movement {
private:
    int heightTerrain;
    int widthTerrain;

protected:
    Vecteur moveTowards(DIRECTION direction, Vecteur position);
    
public:
    Movement(int heightTerrain, int widthTerrain) { this->heightTerrain = heightTerrain; this->widthTerrain = widthTerrain; }
    ~Movement() {}

    int getHeight() const { return heightTerrain; }
    int getWidth() const { return widthTerrain; }

    virtual Vecteur Move(Vecteur start, Vecteur objective);
};