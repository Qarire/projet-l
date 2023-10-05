#include "Game.h"

Game* Game::Instance{nullptr};

Game* Game::GetInstance() {
    if(Instance == nullptr)
        Instance = new Game();
    
    return Instance;
} 