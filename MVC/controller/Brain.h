#pragma once

#include "CharacterData.h"
#include "Action.h"

class Brain {

    private:
        CharacterData character;
        vector<Action> actionlist;
    
    public:
    
        Brain(CharacterData charac, vector<Action> list );
        ~Brain();
        
        CharacterData getCharacter() const;
        void setCharacterData(CharacterData c);
        
        vector<Action> getActionlist() const;

        Action findPriority();

        void Update(float dt);
}