#pragma once

#include "Game.h"

class Drawer {
private:
//! Singleton
    Drawer() {}
    static Drawer* Instance;

//! Singleton

    Game* game;

public:
    //! Singleton
    static Drawer* GetInstance() { 
        if(Instance == nullptr)
            Instance = new Drawer();
        
        return Instance;
    } 
    //! Singleton

    void Init() {
        game = Game::GetInstance();
    }

    void Draw(float dt) {
        if(game == nullptr) throw std::invalid_argument("Updater hasn't been initialized");

        throw std::runtime_error("not implemented");        
    }

};