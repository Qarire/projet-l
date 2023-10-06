#pragma once

#include "Condition.h"

class ConditionTrue : public Condition {
public:
// Inherited Methods
    bool isConditionMet() const override {
        return true;
    }
};