#pragma once
#include "Game.h"


class Updater {
private:
//! Singleton
    Updater() {}
    static Updater* Instance;

//! Singleton

    Game* game;

public:
    //! Singleton
    static Updater* GetInstance();
    //! Singleton

    void Init() {
        game = Game::GetInstance();
    }

    void Update(float dt) {
        if(game == nullptr) throw std::invalid_argument("Updater hasn't been initialized");

        vector<Brain*> brainList = game->getBrainList();

        for(int i = 0; i < brainList.size(); i++) {
            brainList[i]->Update(dt);
        }

        game->cleanTheDeads();
    }

};