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

        if(condition->isConditionMet()) {
            if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                if(!switchCondition->isConditionMet()) {
                    vector<CharacterData*> characterDatas;
                
                    characterDatas = field->findAllCharacterData(Position(myMouse.y, myMouse.x));

                    if(characterDatas.size() > 0) {
                        switchCondition->setSwitch(true);

                        (ConsequenceCharacterFollowMouse)consequence->setCharacterData(characterDatas[0]);
                    }
                    else {
                        return false;
                    }
                }
               
                consequence->run();

                return true;
            }
            else {
                (ConsequenceCharacterFollowMouse)consequence->setCharacterData(nullptr);
                switchCondition->setSwitch(false);
                return false;
            }            
        }

        return false;
    }
};