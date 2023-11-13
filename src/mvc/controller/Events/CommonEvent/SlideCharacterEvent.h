#pragma once

#include "Event.h"
#include "SwitchCondition.h"
#include "InputConditionMouse.h"
#include "ConsequenceCharacterFollowMouse.h"
#include "ConditionCompositeOr.h"

class SlideCharacterEvent : public Event {
public:

    SwitchCondition* switchCondition = new SwitchCondition(false);


    SlideCharacterEvent() 
    : Event(
        new ConditionCompositeOr(
            switchCondition,
            new InputConditionMouseDown(MOUSE_BUTTON_LEFT)
        ),   
        new ConsequenceCharacterFollowMouse() 
    ) {}


    virtual bool runEvent() const override {
        Field* field = Field::GetInstance();
        Vector2 myMouse = GetMousePosition();
        ConsequenceCharacterFollowMouse* consequenceCasted =  dynamic_cast<ConsequenceCharacterFollowMouse*> (this->consequence);

        if(condition->isConditionMet()) {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

                if(!switchCondition->isConditionMet()) {

                    vector<CharacterData*> characterDatas;
                
                    characterDatas = field->getCharacterDataList(); 
                    // TODO get the right character
                    // TODO modify the consequence to set up the character to a round up value and in the field
                    // TODO separate view from model

                    if(characterDatas.size() > 0) {
                        
                        switchCondition->setSwitch(true);

                        consequenceCasted->setCharacterData(characterDatas[0]);
                    }
                    else {
                        return false;
                    }
                }
               
                consequenceCasted->run();

                return true;
            }
            else {
                consequenceCasted->setCharacterData(nullptr);
                switchCondition->setSwitch(false);
                return false;
            }            
        }

        return false;
    }
};