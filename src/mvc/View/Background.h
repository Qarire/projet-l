#pragma once

#include "Drawable.h"
#include "Field.h"

class Background : public Drawable {
private:
// Fields
    Texture2D spriteTexture;
    Texture2D groundSpriteTexture;

public:
// Constructors
    Background(Texture2D spriteTexture, Texture2D groundSpriteTexture) {
        this->spriteTexture = spriteTexture;
        this->groundSpriteTexture = groundSpriteTexture;
    }


// Properties
    static float getFieldHeight() {
        return float(GetScreenHeight() * 0.75);
    }
    static float getFieldTile() {
        Field* field = Field::GetInstance();
        return getFieldHeight()/(field->getHeight()+1);
    }
    static float getFieldWidth() {
        Field* field = Field::GetInstance();
        return getFieldTile()*field->getWidth();
    }
    static float getNegativeFieldWidth() {
        Field* field = Field::GetInstance();
        return GetScreenWidth() - getFieldTile()*field->getWidth();
    }
    static pair<float, float> getVisual0() {
        return make_pair(0, getNegativeFieldWidth() / 2);
    }


// Inherited Methods
    void Draw() override {
        Field* field = Field::GetInstance();

        for(int i = 0; i < GetScreenHeight()/getFieldTile(); i++) {
            for(int j = 0; j < GetScreenWidth()/getFieldTile(); j++) {
                DrawTexturePro(
                    groundSpriteTexture,
                    Rectangle{0, 0, float(groundSpriteTexture.width), float(groundSpriteTexture.height/5)},
                    Rectangle{j * getFieldTile(), i * getFieldTile(), getFieldTile(), getFieldTile()},
                    Vector2{0, 0},
                    0,
                    WHITE
                );
            }
        }
        

        for(int i = 0; i < field->getHeight(); i++) {
            for(int j = 0; j < field->getWidth(); j++) {
                DrawTexturePro(
                    spriteTexture,
                    Rectangle{0, 0, float(spriteTexture.height/14.0), float(spriteTexture.width/11.0)},
                    Rectangle{ getNegativeFieldWidth() / 2 + j * getFieldTile(), i * getFieldTile(), getFieldTile(), getFieldTile()},
                    Vector2{0, 0},
                    0,
                    WHITE
                );
            }
        }
    }
};