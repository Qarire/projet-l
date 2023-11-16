#pragma once

#include <iostream>
#include <stdlib.h>   
#include <Field.h>

using namespace std;
class Action {
protected:
    
    float time;
    float chrono;
    bool cooldown;
    
private:

    virtual void Act() = 0;
    virtual bool void CooldownAction(bool _cooldown) = 0;
    float getTime() const { return time; };
    float getChrono() const { return chrono; };

    void Update ();
    
};