#pragma once

#include <iostream>
#include "Jeu.h"

using namespace std;

class Displayer { 
private:

    // ! Singleton
    static Displayer* instance;

    Displayer() {}
    // ! Singleton

public:

    // ! Singleton
    static Displayer* getInstance() {
        if(instance==nullptr){
            instance = new Displayer();
        }
        return instance;
    }    
    ~Displayer() {}

    void Display() const;
};