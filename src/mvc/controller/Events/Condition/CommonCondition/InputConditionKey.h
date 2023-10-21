#pragma once

#include "InputCondition.h"

class InputConditionKeyPressed : public InputCondition {
public:
    InputConditionKeyPressed(int key) : InputCondition(key) {}

    bool isConditionMet() const override {

        return IsKeyPressed(key);
    }
};

class InputConditionKeyDown : public InputCondition {
public:
    InputConditionKeyDown(int key) : InputCondition(key) {}

    bool isConditionMet() const override {

        return IsKeyDown(key);
    }
};

class InputConditionKeyReleased : public InputCondition {
public:
    InputConditionKeyDown(int key) : InputCondition(key) {}

    bool isConditionMet() const override {

        return IsKeyReleased(key);
    }
};