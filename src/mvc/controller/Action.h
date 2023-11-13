#pragma once

#include <iostream>
#include <stdlib.h>   


using namespace std;
class Action {
    private:

    float time;
    float chrono;
    bool cooldown;
    
    virtual void Act() = 0;

    float getTime() const { return time; };
    float getChrono() const { return chrono; };

    void Update ();

};