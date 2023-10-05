#include "Drawer.h"

Drawer* Drawer::Instance{nullptr};

Drawer* Drawer::GetInstance() {
    if(Instance == nullptr)
        Instance = new Drawer();
    
    return Instance;
} 