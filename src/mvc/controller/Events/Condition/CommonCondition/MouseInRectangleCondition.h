#pragma once

#include "raylib.h"
#include "Condition.h"


class MouseInRectangleCondition : public Condition {
private:
    Rectangle hitbox;

public:
    ButtonCondition(Rectangle hitbox) {
        this->hitbox = hitbox;
    }


    bool isConditionMet() const override {
        return ((myMouse.x > hitbox.x && myMouse.x < hitbox.x + hitbox.width) && (myMouse.y > hitbox.y  && myMouse.y < hitbox.y + hitbox.height));
    };
};