#include "Action.h"

Action::Action(float l, float c, bool r) {
    lastFor = l;
    chrono = c;
    isRunning = r;
}

float Action::getLastFor() const {
    return lastFor;
}

float Action::getChrono() const {
    return chrono;
}

void Action::Update(float dt){

}