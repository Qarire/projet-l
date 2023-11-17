#pragma once

#include <string>
#include "raylib.h"

struct SpriteData {
public:
// Fields
    std::string name;

    Rectangle spriteRectangle;
    int fps;
    std::pair<int, int> firstFrame;
    bool isLooping;
};