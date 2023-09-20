#pragma once

#include <iostream>
#include "../Jeu/Terrain.h"

using namespace std;

class Displayer {
private:
    Terrain* terrain;

public:
    Displayer(Terrain* terrain) {
        this->terrain = terrain;
    }
    ~Displayer() {}

    void Display() const;
};