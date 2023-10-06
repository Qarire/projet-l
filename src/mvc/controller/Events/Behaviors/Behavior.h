#pragma once

#include <vector>
#include "Event.h"

class Behavior {
private:
// Fields
    vector<Event*> eventList;

public:
// Constructors
    Behavior(vector<Event*> eventList) {
        this->eventList = eventList;
    }
    ~Behavior() {
        for(int i = 0; i < eventList.size(); i++) {
            delete eventList[i];
        }

        eventList.clear();
    }


// Public Methods
    virtual void runBehavior() const {
        for(int i = 0; i < eventList.size(); i++) {
            eventList[i]->runEvent();
        }
    }
}