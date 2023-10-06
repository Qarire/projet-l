#pragma once

#include <vector>
#include "Behavior.h"


class BehaviorComposite : public Behavior {
private:
// Fields
    vector<Behavior*> behaviorList;


public:
// Constructor
    BehaviorComposite(vector<Behavior*> behaviorList) {
        this->behaviorList = behaviorList;
    }
    ~BehaviorComposite() {
        for (int i = 0; i < this->behaviorList.size(); i++) {
            delete this->behaviorList[i];
        }

        behaviorList.clear();
    }

// Public Methods
    void runBehavior() const override {
        for(int i = 0; i < eventList.size(); i++) {
            behaviorList[i]->runBehavior();
        }
    }
}