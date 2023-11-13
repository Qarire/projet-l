#pragma once 

#include <cmath>
#include "Attack.h"

class Melee: public Attack {
public:
    Melee() : Attack() {}
    ~Melee() {}

    bool canTouch() override;
    int damage() override;
    void Act() override;
  
};