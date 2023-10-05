#include "Updater.h"

Updater* Updater::Instance{nullptr};

Updater* Updater::GetInstance() {
    if(Instance == nullptr)
        Instance = new Updater();
    
    return Instance;
} 