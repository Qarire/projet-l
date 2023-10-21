#pragma once

struct ValueMaxed {
    int Max;
    int Value;


    ValueMaxed() {
        Max = 0;
        Value = 0;
    }
    ValueMaxed(int value) {
        this->Max = value;
        this->Value = value;
    }
    ValueMaxed(int max, int value) {
        this->Max = max;
        this->Value = value;
    }
};