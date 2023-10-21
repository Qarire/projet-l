#pragma once

#include "ValueMaxed.h"
#include "Type.h"

struct Stats {

    ValueMaxed hp = 100;
    ValueMaxed def = 0;
    ValueMaxed atk = 0;

    Stats() = default;
    Stats(ValueMaxed hp, ValueMaxed def, ValueMaxed atk) {
        this->hp = hp;
        this->def = def;
        this->atk = atk;
    }
};