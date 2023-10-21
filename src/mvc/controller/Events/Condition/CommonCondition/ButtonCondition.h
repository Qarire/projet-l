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
    ButtonCondition(int x, int y, int width, int height) {
        hitbox.x = x;
        hitbox.y = y;
        hitbox.width = width;
        hitbox.height = height;
    }


    bool isConditionMet() const override {
        Vector2 myMouse = GetMousePosition();

        return ((myMouse.x > hitbox.x && myMouse.x < hitbox.x + hitbox.width) && (myMouse.y > hitbox.y  && myMouse.y < hitbox.y + hitbox.height));
    };
};