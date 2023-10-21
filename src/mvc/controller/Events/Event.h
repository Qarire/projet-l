#pragma once

#include "Condition.h"
#include "ConditionTrue.h"
#include "Consequence.h"

class Event {
private:
//Fields
    Condition* condition;
    Consequence* consequence;

public:
// Constructor
    Event(Condition* condition, Consequence* consequence) {
        this->condition = condition;
        this->consequence = consequence;
    }
    ~Event() {
        delete condition;
        delete consequence;
    }

// Properties
    Condition* getCondition() const { return this->condition; }
    Consequence* getConsequence() const { return this->consequence; }

// Public Methods
    virtual bool runEvent() const {
        if(condition->isConditionMet()) {
            consequence->run();
            return true;
        }

        return false;
    }
};