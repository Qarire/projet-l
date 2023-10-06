#pragma once

#include "ConditionComposite.h"

class ConditionCompositeAnd : ConditionComposite {
public:
// Constructor
    ConditionCompositeAnd(Condition* firstCondition, Condition* secondCondition) 
    : ConditionComposite(firstCondition, secondCondition) {}


// Inherited Methods
    bool isConditionMet() const override {
        return firstCondition && secondCondition;
    }
};