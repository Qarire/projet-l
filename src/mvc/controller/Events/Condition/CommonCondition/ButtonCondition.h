#pragma once

#include "raylib.h"
#include "Condition.h"


class ButtonCondition : public Condition {
private:
    Rectangle hitbox;

public:
    ButtonCondition(Rectangle hitbox) {
        this->hitbox = hitbox;
    }


    bool isConditionMet() const override {
        Vector2 myMouse = GetMousePosition();
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            return ((myMouse.x > hitbox.x && myMouse.x < hitbox.x + hitbox.width) && (myMouse.y > hitbox.y  && myMouse.y < hitbox.y + hitbox.height));
        return false;
    };
};