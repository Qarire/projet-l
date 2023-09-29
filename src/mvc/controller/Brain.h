#pragma once

#include <iostream>
#include <vector>
#include "CharacterData.h"
#include "Action.h"

using namespace std;

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

        Action findPriority(CharacterData charac,vector<Action> listact);
       
        pair<int,CharacterData> FindpairCharacterDistance(CharacterData charac, int heightTerrai, int widthTerrain);

        void Update(float dt);
};