#pragma once

#include "EventCondition.h"
#include "CharacterData.h"

class SlideCharacterEvent : public Event {
private:
    bool isSliding = false;
    CharacterData* characterData = nullptr;


// Private Methods
    void updatePositionToMouse() {
        Vector2 myMouse = GetMousePosition();

        characterData->setPosition(Position(myMouse.y - Background::getFieldTile()/2, myMouse.x - Background::getFieldTile()/2 - Background::getNegativeFieldWidth()/2));
    }

public:
    SlideCharacterEvent() {}


    bool runEvent() override {
        Field* field = Field::GetInstance();
        Vector2 myMouse = GetMousePosition();


        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            if(!isSliding) {

                vector<CharacterData*> characterDatas = field->getCharacterDataList();

                if(characterDatas.size() > 0) {
                        
                    isSliding = true;
                    characterData = characterDatas[0];
                    updatePositionToMouse();
                }
                else {
                    return false;
                }
            }
            else {
            
                updatePositionToMouse();
                return true;
            }
        }
        else {
            characterData = nullptr;
            isSliding = false;
            return false;
        }

        return false;
    }


    // bool runEvent() const override {
    //     Field* field = Field::GetInstance();
    //     Vector2 myMouse = GetMousePosition();
    //     ConsequenceCharacterFollowMouse* consequenceCasted =  dynamic_cast<ConsequenceCharacterFollowMouse*> (this->consequence);

    //     if(condition->isConditionMet()) {
    //         if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

    //             if(!switchCondition->isConditionMet()) {

    //                 vector<CharacterData*> characterDatas;
                
    //                 characterDatas = field->getCharacterDataList(); 
    //                 // TODO get the right character
    //                 // TODO modify the consequence to set up the character to a round up value and in the field
    //                 // TODO separate view from model

    //                 if(characterDatas.size() > 0) {
                        
    //                     switchCondition->setSwitch(true);

    //                     consequenceCasted->setCharacterData(characterDatas[0]);
    //                 }
    //                 else {
    //                     return false;
    //                 }
    //             }
               
    //             consequenceCasted->run();

    //             return true;
    //         }
    //         else {
    //             consequenceCasted->setCharacterData(nullptr);
    //             switchCondition->setSwitch(false);
    //             return false;
    //         }            
    //     }

    //     return false;
    // }
};