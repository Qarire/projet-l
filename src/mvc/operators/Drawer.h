#pragma once

#include <vector>
#include "Drawable.h"

using namespace std;

class Drawer {
private:
//! Singleton
    Drawer() {}
    static Drawer* Instance;

//! Singleton

    vector<Drawable*> drawables;

public:
    //! Singleton
    static Drawer* GetInstance();
    //! Singleton

    void Init(vector<Drawable*> drawables) {
        this->drawables = drawables;
    }

    void Draw(float dt) {
        for(int i = 0; i < drawables.size(); i++) {
            drawables[i]->Draw(dt);
        }
    }

};