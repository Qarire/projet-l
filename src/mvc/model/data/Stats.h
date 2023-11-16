#pragma once

#include "ValueMaxed.h"
#include "Type.h"

struct Stats {

    ValueMaxed hp = 100;
    ValueMaxed def = 0;
    ValueMaxed atk = 0;
    ValueMaxed range = 0;

    Stats() = default;
    Stats(ValueMaxed hp, ValueMaxed def, ValueMaxed atk, ValueMaxed range) {
        this->hp = hp;
        this->def = def;
        this->atk = atk;
        this->range = range;
    }
};