#pragma once

#include <vector>
#include "Consequence.h"

class ConsequenceComposite : public Consequence {
private:
// Fields
    vector<Consequence*> consequenceList;

public:
// Constructor
    ConsequenceComposite(vector<Consequence*> consequenceList) {
        this->consequenceList = consequenceList
    }
    ~ConsequenceComposite() {
        for(int i = 0; i < consequenceList.size(); i++) {
            delete consequenceList[i];
        }

        consequenceList.clear();
    }


// Inherited Methods
    void run() override {
        for(int i = 0; i < consequenceList.size(); i++) {
            consequenceList[i].run();
        }
    }
};