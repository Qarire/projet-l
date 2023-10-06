#pragma once

#include "Condition.h"

class ConditionTrue : public Condition {
// Inherited Methods
    bool isConditionMet() const override {
        return true;
    }
};