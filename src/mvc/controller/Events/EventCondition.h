#pragma once

#include "Event.h"
#include "Condition.h"
#include "ConditionTrue.h"
#include "Consequence.h"

class EventCondition : public Event {
protected:
//Fields
    Condition* condition;
    Consequence* consequence;

public:
// Constructor
    EventCondition(Condition* condition, Consequence* consequence) {
        this->condition = condition;
        this->consequence = consequence;
    }
    ~EventCondition() {
        delete condition;
        delete consequence;
    }

// Properties
    Condition* getCondition() const { return this->condition; }
    Consequence* getConsequence() const { return this->consequence; }

// Public Methods
    virtual bool runEvent() const override {
        if(condition->isConditionMet()) {
            consequence->run();
            return true;
        }

        return false;
    }
};