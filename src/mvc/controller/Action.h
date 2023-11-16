#pragma once

#include <iostream>
#include <stdlib.h>   
#include <Field.h>

using namespace std;
class Action {
protected:
    
    float time;
    float cooldownTime;
    float chrono;
    bool isInCooldown;

    virtual void Act() = 0;

    float getTime() const { return time; };
    float getChrono() const { return chrono; };

public:
    Action(float time, float cooldownTime = 0) {
        this->time = time;
        this->cooldownTime = cooldownTime;
        this->chrono = 0;
        this->isInCooldown = false;
    }

    void Update (float dt) {
        chrono += dt;

        float tmp = chrono;

        if(!isInCooldown) {
            while(tmp >= time) {
                chrono = 0;
                tmp -= time;

                Act();
                isInCooldown = true;
            }
        }
        else{
            if(chrono >= cooldownTime) {
                chrono = 0
                isInCooldown = false;
            }
        }




    }
    
};