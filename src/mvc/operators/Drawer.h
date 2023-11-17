#pragma once

#include <vector>
#include <string>
#include "Drawable.h"
#include "AssetData.h"
#include "SpriteData.h"

using namespace std;

class Drawer {
private:
//! Singleton
    Drawer() {}
    static Drawer* Instance;

//! Singleton

    vector<Drawable*> drawables;
    AssetData* asset;

public:
    //! Singleton
    static Drawer* GetInstance();
    //! Singleton

    void Init(vector<Drawable*> drawables) {
        this->drawables = drawables;

        Texture2D spriteTexture = LoadTexture("img/Sprite.png");

        asset = new AssetData(
            "main asset",
            spriteTexture,
            make_pair(11, 14),
            vector<SpriteData*>{
                new SpriteData{"Tank_icon", Rectangle{0, 1, 5, 1}, 1, make_pair(0, 0), true},
                new SpriteData{"Melee_icon", Rectangle{0, 2, 5, 1}, 1, make_pair(0, 0), true},
                new SpriteData{"Archer_icon", Rectangle{0, 3, 5, 1}, 1, make_pair(0, 0), true},
                new SpriteData{"Sorcerer_icon", Rectangle{0, 4, 5, 1}, 1, make_pair(0, 0), true},
                new SpriteData{"Healer_icon", Rectangle{0, 5, 5, 1}, 1, make_pair(0, 0), true},
            }
        );
    }

    void addDrawable(Drawable* drawable) {
        drawables.push_back(drawable);
    }

    SpriteData* getSpriteData(std::string spriteName) {
        return asset->getSpriteData(spriteName);
    }
    AssetData* getAssetData() {
        return asset;
    }

    void Draw(float dt) {
        for(int i = 0; i < drawables.size(); i++) {
            drawables[i]->Draw(dt);
        }
    }

};