#pragma once

#include "Condition.h"

class InputCondition : public Condition {
protected:
    int key;

public:
    InputCondition(int key) {
        this->key = key;
    }

    virtual bool isConditionMet() const override = 0;
}