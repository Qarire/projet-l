#pragma once
#include "raylib.h"
#include <iostream>
using namespace std;
struct DataSprite {
    // pas besoin de name, path et dictionnary, ni de idata, asset, jsoncontent, uniquement Sprite et DataSprite
    Texture2D Texture;
    pair <int,int> index;
    int Fps;
    int FirstFrame;
    bool isLooping;
};