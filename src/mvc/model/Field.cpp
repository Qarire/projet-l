#include "Field.h"

Field* Field::Instance{nullptr};

Field* Field::GetInstance() { 
    if(Instance == nullptr)
        Instance = new Field();
    
    return Instance;
} 