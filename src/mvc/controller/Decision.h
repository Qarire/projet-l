#pragma once

#include <iostream>
#include <utility>
#include <stdlib.h>   

using namespace std;

class Decision {

    private:
    
    CharacterData* character;
    vector<Action*> actionlist;
    
    public:

    CharacterData* getCharacterData() const;
    vector<Action*> getActionlist() const;

    virtual void decideWhereToMove(CharaterData* character)= 0 ;
    virtual void decideAction() = 0;
    virtual void prioritySystem() = 0;

    

    
}