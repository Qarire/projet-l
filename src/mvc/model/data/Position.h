#pragma once

#include <iostream>
#include <cmath>
#include "raylib.h"

using namespace std;

struct Position {
public : 
    float x,y; /** @brief les coordonnees en x et en y de notre Position*/

// Constructor
    Position ();
    Position(float y, float x);
    ~Position();

// Static Methods
    static float distance(Position pos1, Position pos2);

// Convertor
    Vector2 toVector2();

// Operators
    bool operator==(Position p);
    Position operator+(Position p);
    Position operator+(float a);
    Position operator-(Position p);
    Position operator-(float a);
};