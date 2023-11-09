#pragma once

#include "Event.h"

class SlideCharacterEvent : public Event {
public:
    public SlideCharacterEvent() 
    : Event(
        new InputConditionMouseDown(MOUSE_BUTTON_LEFT), 
        new ConsequenceMoveCharacter() // TODO make that class, it'll take a characte data in a setter and move it following the mouse
    )   // TODO to do that I'll probably have to create a new SwitchCOndition that'll contain a bool that can be switched and it'll be the condition OR condition to this event 
     // TODO When the mouse is not being pressed anymore, this bool will be turned to off, and we will place the character either to a valid place or to his original position
     // TODO so this class will have to save : the current Character being moved and his original position
    {}


    virtual bool runEvent() const override {
        Field* field = Field::GetInstance();

        if(condition->isConditionMet()) {
            
            for(int i = 0; i < field->getCharacterDataList().size(); i++) {
                // Find if I'm on a character or not
                // if yes take it and give it to ConsequenceMoveCharacter(consequence)->setCharacter(...);
                // Then run the consequence
                // You might have to do a dynamic cast
            }


            ConsequenceMoveCharacter(consequence)->setCharacter();
            consequence->run();
            return true;
        }

        return false;
    }
}