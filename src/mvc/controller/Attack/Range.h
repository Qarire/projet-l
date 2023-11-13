#pragma once 

#include <cmath>
#include "Attack.h"

class Range: public Attack {
public:
    Range() : Attack() {}
    ~Range() {}

    bool canTouch() override;
    int damage() override;
    void Act() override;
  
};