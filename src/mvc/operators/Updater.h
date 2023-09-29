#include "Game.h"


class Updater {
private:
//! Singleton
    Updater() {}
    static Updater* Instance = nullptr;

//! Singleton

    Game* game = nulltpr;

public:
    //! Singleton
    static Updater* GetInstance() { 
        if(Instance == nullptr)
            Instance = new Updater();
        
        return Instance;
    } 
    //! Singleton

    void Init() {
        game = Game.GetInstance();
    }

    void Update(dt: float) {
        if(game == nullptr) throw std::bad_alloc("Updater hasn't been initialized");

        vector<Brain*> brainList = game.getBrainList();

        for(int i = 0; i < brainList.size(); i++) {
            brainList[i]->Update(dt);
        }

        game.cleanTheDeads();
    }

};