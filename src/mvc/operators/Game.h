#pragma once

#include <Vector>

#include "Field.h"
#include "Brain.h"

using namespace std;

class Game {
private:
//! Singleton
    Game() {}
    static Game* Instance;

//! Singleton

// Fields
    vector<Brain*> brainList; 

    Field* field = nullptr;


// Private Methods
    int findBrainIndex(Brain* brain) {
        for(int i=0; i<brainList.size(); i++) {
            if(brainList[i] == brain)
                return i;
        }

        throw std::invalid_argument("This Brain does not exists in the game");
    }

public:
    //! Singleton
    static Game* GetInstance() { 
        if(Instance == nullptr)
            Instance = new Game();
        
        return Instance;
    } 
    //! Singleton

    ~Game() {
        for(int i = 0; i < brainList.size(); i++) {
            delete brainList[i];
        }

        brainList.clear();
    }

    void Init() {
        field = Field::GetInstance();
    }


// Public Methods

    vector<Brain*> getBrainList() const {
        return brainList;
    }
    void addBrain(Brain* newBrain) {
        brainList.push_back(newBrain);
        field->addCharacterData(newBrain->getCharacterData());
    }
    void removeBrain(Brain* brain) {
        int index = findBrainIndex(brain);

        field->removeCharacterData(brain->getCharacterData());

        brainList.erase(brainList.begin() + index);
        delete brain;
    }

    void cleanTheDeads() {
        for(int i = 0; i < brainList.size(); i++) {
            if(brainList[i]->getCharacterData()->getisDead()) {
                removeBrain(brainList[i]);

                cleanTheDeads();
                return;
            }
        }
    }
};