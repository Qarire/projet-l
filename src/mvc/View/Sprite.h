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
    AssetData* assetData;
    SpriteData* currentSpriteData;

    Position visualPosition;
    std::vector<std::vector<Rectangle>> frames; // width, height
    std::pair<int, int> currentFrameIndex; // width, height

    float timeSinceLastFrame;


// Private Properties
    int getCurrentFrameIndexAsInt() const {
        return (currentFrameIndex.first) + currentFrameIndex.second * currentSpriteData->spriteRectangle.width;
    }


// Private Methods
    void buildFrames() {
        frames.clear();
        
        std::pair<float, float> tileSize = std::make_pair( // width , height
            assetData->getTexture().width / assetData->getTextureSize().first,
            assetData->getTexture().height / assetData->getTextureSize().second
        );
        std::pair<float, float> startPoint = std::make_pair( // width , height
            currentSpriteData->spriteRectangle.x * tileSize.first,
            currentSpriteData->spriteRectangle.y * tileSize.second
        );


        for(int k = 0; k < currentSpriteData->spriteRectangle.height - currentSpriteData->spriteRectangle.y; k++) {
            std::vector<Rectangle> row;
            for(int i = 0; i < currentSpriteData->spriteRectangle.width - currentSpriteData->spriteRectangle.x; i++) {
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
    Sprite(AssetData* AssetData, std::string spriteName, Position visualPosition) {
        this->assetData = AssetData;
        this->currentSpriteData = assetData->getSpriteData(spriteName);
        this->visualPosition = visualPosition;
        buildFrames();

        currentFrameIndex = currentSpriteData->firstFrame;

        timeSinceLastFrame = 0;
    }


// Public Methods
    void Draw(float dt) override {
        Rectangle currentFrame = frames[currentFrameIndex.first][currentFrameIndex.second];

        Vector2 frameCenter = Vector2{currentFrame.width/2, currentFrame.height/2};

        DrawTexturePro(
            assetData->getTexture(),
            currentFrame,
            Rectangle{visualPosition.x - frameCenter.x, visualPosition.y - frameCenter.y, Background::getFieldTile(), Background::getFieldTile()},
            frameCenter,
            0,
            WHITE
        );
    }

    
};