#pragma once

#include <vector>
#include "raylib.h"
#include "Drawable.h"
#include "AssetData.h"
#include "SpriteData.h"
#include "Position.h"

class Sprite : public Drawable {
private:
// Fields
    SpriteData* currentSpriteData;
    AssetData* assetData;

    CharacterData* characterData;

    Position visualOffset;
    std::vector<std::vector<Rectangle>> frames; // width, height
    std::pair<int, int> currentFrameIndex; // width, height

    float timeSinceLastFrame;


// Private Properties
    int getCurrentFrameIndexAsInt() const {
        return (currentFrameIndex.first) + currentFrameIndex.second * currentSpriteData->spriteRectangle.width;
    }


// Private Methods
    void buildFrames() {
        cout << "heeeey" << endl;
        frames.clear();
        
        std::pair<float, float> tileSize = std::make_pair( // width , height
            assetData->getTexture().width / assetData->getTextureSize().first,
            assetData->getTexture().height / assetData->getTextureSize().second
        );
        std::pair<float, float> startPoint = std::make_pair( // width , height
            currentSpriteData->spriteRectangle.x * tileSize.first,
            currentSpriteData->spriteRectangle.y * tileSize.second
        );


        for(int k = 0; k < currentSpriteData->spriteRectangle.height; k++) {
            std::vector<Rectangle> row;
            for(int i = 0; i < currentSpriteData->spriteRectangle.width; i++) {
                row.push_back(Rectangle{
                    startPoint.first + i * tileSize.first,
                    startPoint.second + k * tileSize.second,
                    tileSize.first,
                    tileSize.second
                });
            }
            frames.push_back(row);
        }
    }

    bool hasFrame(int index) {
        return hasFrame(std::make_pair(index/currentSpriteData->spriteRectangle.width, index%(int)currentSpriteData->spriteRectangle.width));
    }
    bool hasFrame(std::pair<int, int> index) {
        return !(index.first < 0 || index.second < 0 || index.first >= currentSpriteData->spriteRectangle.height || index.second >= currentSpriteData->spriteRectangle.width);
    }

    void setFrame(int index) {
        setFrame(std::make_pair(index/currentSpriteData->spriteRectangle.width, currentSpriteData->spriteRectangle.width));
    }
    void setFrame(std::pair<int, int> index) {
        if(!hasFrame(index)){
            throw new std::invalid_argument("the index is out of range, this frame doesn't exists");
        }
        currentFrameIndex = index;
    }

    bool hasNextFrame() {
        if(hasFrame(getCurrentFrameIndexAsInt() +1))
            return true;
        return false;
    }
    void nextFrame(float dt) {
        if(currentSpriteData->fps != 0) { // if FPS is at 0, then the image is static, useful for tilesets
            timeSinceLastFrame += dt;

            float tmp = timeSinceLastFrame;
            while(tmp >= 1.0/(float)currentSpriteData->fps) {
                timeSinceLastFrame = 0;
                tmp -= 1.0/(float)currentSpriteData->fps;

                if(hasNextFrame())
                    setFrame(getCurrentFrameIndexAsInt() +1);
                else if(currentSpriteData->isLooping)
                    setFrame(0);
            }
        }
    }

    
public:
// Constructors
    Sprite(std::string spriteName, CharacterData* characterData, Position visualOffset) {
        Drawer* drawer = Drawer::GetInstance();

        this->assetData = drawer->getAssetData();

        this->currentSpriteData = drawer->getSpriteData(spriteName);

        this->characterData = characterData;

        this->visualOffset = visualOffset;
        buildFrames();

        currentFrameIndex = currentSpriteData->firstFrame;

        timeSinceLastFrame = 0;
    }


// Public Methods
    void Draw(float dt) override {
        Rectangle currentFrame = frames[currentFrameIndex.second][currentFrameIndex.first];

        Vector2 frameCenter = Vector2{currentFrame.width/2, currentFrame.height/2};


        DrawTexturePro(
            assetData->getTexture(),
            currentFrame,
            Rectangle{visualOffset.x + characterData->getPosition().x, visualOffset.y + characterData->getPosition().y, Background::getFieldTile(), Background::getFieldTile()},
            Vector2{0,0},
            0,
            WHITE
        );
    }

    
};