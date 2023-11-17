#pragma once

#include <vector>
#include "EventCondition.h"


class Behavior {
private:
// Fields
    std::vector<EventCondition*> EventConditionList;

public:
// Constructors
    Behavior(std::vector<EventCondition*> EventConditionList) {
        this->EventConditionList = EventConditionList;
    }
    ~Behavior() {
        for(int i = 0; i < EventConditionList.size(); i++) {
            delete EventConditionList[i];
        }

        EventConditionList.clear();
    }


// Public Methods
    virtual void runBehavior() const {
        for(int i = 0; i < EventConditionList.size(); i++) {
            EventConditionList[i]->runEvent();
        }
    }
};