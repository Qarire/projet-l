#pragma once

#include "InputCondition.h"

class InputConditionMousePressed : public InputCondition {
public:
    InputConditionMousePressed(int key) : InputCondition(key) {}

    bool isConditionMet() const override {

        return IsMouseButtonPressed(key);
    }
};

class InputConditionMouseDown : public InputCondition {
public:
    InputConditionMouseDown(int key) : InputCondition(key) {}

    bool isConditionMet() const override {

        return IsMouseButtonDown(key);
    }
};

class InputConditionMouseReleased : public InputCondition {
public:
    InputConditionMouseReleased(int key) : InputCondition(key) {}

    bool isConditionMet() const override {

        return IsMouseButtonReleased(key);
    }
};