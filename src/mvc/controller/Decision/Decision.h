#pragma once

#include <iostream>
#include <utility>
#include <stdlib.h>
#include <Field.h> 
#include <Action.h>

using namespace std;

class Decision {

    private:
    
    CharacterData* character;
    Action* currentAction;
    
    public:

    Decision() {}
    Decision(CharacterData* _character, Action _actionlist);
    CharacterData* getCharacterData() const;
   

    
    virtual Action* prioritySystem() = 0;

    void uptdate (float dt) {
        if(currentAction!=nullptr) {
            currentAction.Act(dt);
            if(currentAction.readFlagsDone()==true) {
                currentAction=nullptr;
            }
        }else{
            currentAction = prioritySystem();
        } 
    } 
}