#pragma once

#include "Condition.h"

class ConditionComposite : public Condition {
protected:
// Fields
    Condition* firstCondition;
    Condition* secondCondition;

public:
// Constructor
    ConditionComposite(Condition* firstCondition, Condition* secondCondition) {
        this->firstCondition = firstCondition;
        this->secondCondition = secondCondition;
    }
    ~ConditionComposite() {
        delete firstCondition;
        delete secondCondition;
    }

// Abstract Methods
    virtual bool isConditionMet() const override = 0;
};