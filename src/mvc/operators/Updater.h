#pragma once

#include "Game.h"
#include "Behavior.h"

class Updater {
private:
//! Singleton
    Updater() {}
    static Updater* Instance;

//! Singleton

    Game* game = nullptr;

    Behavior* behavior = nullptr;

public:
    //! Singleton
    static Updater* GetInstance();
    //! Singleton

    void Init(Behavior* behavior) {
        game = Game::GetInstance();
        this->behavior = behavior;
    }

    void Update(float dt) {
        if(game == nullptr || behavior == nullptr) throw std::invalid_argument("Updater hasn't been initialized");

        vector<Brain*> brainList = game->getBrainList();


        behavior->runBehavior();
        for(int i = 0; i < brainList.size(); i++) {
            brainList[i]->Update(dt);
        }

        game->cleanTheDeads();
    }

};