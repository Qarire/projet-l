#pragma once

#include "ValueMaxed.h"
#include "Type.h"

struct Stats {

    ValueMaxed hp = 100;
    ValueMaxed def = 40;
    ValueMaxed atk = 50;
    ValueMaxed range = 3;

    Stats() = default;
    Stats(ValueMaxed hp, ValueMaxed def, ValueMaxed atk, ValueMaxed range) {
        this->hp = hp;
        this->def = def;
        this->atk = atk;
        this->range = range;
    }
};