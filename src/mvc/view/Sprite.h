#pragma once
#include <vector>
#include "raylib.h"
#include "DataSprite.cpp"
#include <iostream>
using namespace std;

class Sprite {
    private :
        DataSprite currentSpriteData;
        vector <vector<Rectangle>> frames;
        pair <int,int> currentFrameindex;
        float timeSinceLastFrame=0;
        float Scale;
        void buildFrames ();
    public : 
        Sprite(string a, string b);
        //faire la classe entity et mettre CharacterData qui en hérite
        //void Initialize (Entity entity);
        pair <int,int> GetCurrentFrameIndex();
        int GetCurrentFrameIndexInt();
        void setTexture (string a, string b);
        bool setFrame (int frame);
        bool setFrame (pair <int, int>);
        bool hasFrame (int frame);
        bool hasFrame (pair <int,int>);
        void Draw (Sprite);
        void NextFrame (float dt); // comme dans le fonctions Update du main
        bool HasNextFrame();
};