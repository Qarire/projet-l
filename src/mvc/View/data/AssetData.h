#pragma once

#include <vector>
#include "raylib.h"
#include "SpriteData.h"

class AssetData {
private:
// Fields
    std::string name;
    Texture2D texture;
    std::pair<int, int> textureSize; // width, height
    std::vector<SpriteData*> sprites;

public: 
// Constructors
    AssetData(std::string name, Texture2D texture, std::pair<int, int> textureSize, std::vector<SpriteData*> sprites) {
        this->name = name;
        this->texture = texture;
        this->textureSize = textureSize;
        this->sprites = sprites;
    }
    ~AssetData() {
        for(int i = 0; i < this->sprites.size(); i++) {
            delete this->sprites[i];
        }
        this->sprites.clear();
    }

// Properties
    std::string getName() const { return this->name; }
    Texture2D getTexture() const { return this->texture; }
    std::pair<int, int> getTextureSize() const { return this->textureSize; }

    SpriteData* getSpriteData(string name) const {
        for (int i = 0; i < sprites.size(); i++) {
            if (sprites[i]->name == name) {
                return sprites[i];
            }
        }
        return nullptr;
    }
};

