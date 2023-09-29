#include "Movement.h"


Position Movement::moveTowards(DIRECTION direction, Position position) {
    switch (direction) {
        case UP:
            position.setY(position.getY() - 1);
            break;
        case LEFT:
            position.setX(position.getX() - 1);
            break;
        case DOWN:
            position.setY(position.getY() + 1);
            break;
        case RIGHT:
            position.setX(position.getX() + 1);
            break;
    }

    return position;
}


Position Movement::Move(Position start, Position objective) {
    return start;
}