#pragma once

#include "Field.h"
#include "Consequence.h"
#include "CharacterData.h"

class ConsequenceCharacterFollowMouse : public Consequence {
private:
// Fields
    CharacterData* characterData = nullptr;

public:
// Constructor
    ConsequenceCharacterFollowMouse() {
        this->characterData = nullptr;
    }

// Public Methods
    void setCharacterData(CharacterData* characterData) {
        this->characterData = characterData;
    }

    void run() override {
        if(characterData != nullptr) {
            Field* field = Field::GetInstance();
            Vector2 myMouse = GetMousePosition();

            characterData->setPosition(Position(myMouse.x - Background::getFieldTile()/2, myMouse.y - Background::getFieldTile()/2));
        }
    }
};