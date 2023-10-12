// DELETE
#include <iostream>
#include "Consequence.h"

using namespace std;

class ConsequenceTestDelete : public Consequence {
public:
// Abstract Mehtods
    void run() override {
        cout << "TEEEEEST" << endl;
    }
};