#pragma once

#include "Behavior.h"


class Updater {
private:
//! Singleton
    Updater() {}
    static Updater* Instance;

//! Singleton

    Behavior* behavior = nullptr;

public:
    //! Singleton
    static Updater* GetInstance();
    //! Singleton

    void Init(Behavior* behavior) {
        this->behavior = behavior;
    }

    void Update(float dt) {
        // REVIEW if(behavior == nullptr) throw std::invalid_argument("Updater hasn't been initialized");

        behavior->runBehavior();
    }

};