#pragma once
// DELETE
#include "Condition.h"

class SwitchCondition : public Condition {
protected:
    bool switch_;

public:
    SwitchCondition(bool switch_) {
        this->switch_ = switch_;
    }

    bool isConditionMet() const override {
        return switch_;
    }

    void setSwitch(bool switch_) {
        this->switch_ = switch_;
    }
};