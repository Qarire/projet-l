#include "Movement.h"

using namespace std;


Vecteur Movement::moveTowards(DIRECTION direction, Vecteur position) {
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


Vecteur Movement::Move(Vecteur start, Vecteur objective) {
    return start;
}