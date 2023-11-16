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
    bool isDone;

    virtual void Act() = 0;

    float getTime() const { return time; };
    float getChrono() const { return chrono; };

public:
    Action(float time, float cooldownTime = 0) {
        this->time = time;
        this->cooldownTime = cooldownTime;
        this->chrono = 0;
        this->isInCooldown = false;
        this->isDone = false;
    }

    bool readFlagIsDone() {
        if(isDone == true) {
            isDone = false;
            return true;
        }

        return false;
    }

    void Update (float dt) {
        chrono += dt;

        float tmp = chrono;

        if(!isInCooldown) {
            while(tmp >= time) {
                chrono = 0;
                tmp -= time;

                Act();
                if(cooldownTimer != 0)
                    isInCooldown = true;
                if(cooldownTimer == 0)
                    isDone = true;
            }
        }
        else{
            if(chrono >= cooldownTime) {
                chrono = 0
                isInCooldown = false;
                
                isDone = true;
            }
        }
    }
    
};