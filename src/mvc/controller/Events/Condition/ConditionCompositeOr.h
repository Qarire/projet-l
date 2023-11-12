#pragma once

#include "ConditionComposite.h"

class ConditionCompositeOr : public ConditionComposite {
public:
// Constructor
    ConditionCompositeOr(Condition* firstCondition, Condition* secondCondition) 
    : ConditionComposite(firstCondition, secondCondition) {}


// Inherited Methods
    bool isConditionMet() const override {
        return firstCondition || secondCondition;
    }
};