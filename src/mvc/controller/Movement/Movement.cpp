#include "Movement.h"


Position Movement::moveTowards(DIRECTION direction, Position position) {
    switch (direction) {
        case UP:
            position.y -= 1;
            break;
        case LEFT:
            position.x -= 1;
            break;
        case DOWN:
            position.y += 1;
            break;
        case RIGHT:
            position.x += 1;
            break;
    }

    return position;
}


Position Movement::Move(Position start, Position objective) {
    return start;
}