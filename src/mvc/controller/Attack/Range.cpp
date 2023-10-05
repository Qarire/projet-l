#include "Range.h"

bool Range::canTouch(Position myPosition, Position targetPosition) {
    int diffX = abs(myPosition.x - targetPosition.x);
    int diffY = abs(myPosition.y - targetPosition.y);

    if(diffX >= 3 || diffY >=3)
        return true;
    return false;
}


int Range::damage(Position myPosition, Position targetPosition) {
    int diffX = abs(myPosition.x - targetPosition.x);
    int diffY = abs(myPosition.y - targetPosition.y);

    int real_dist = diffX + diffY;

    if (real_dist <= 5) {
        return 5;
    } else if (real_dist > 8) {
        return 10;  
    }else 
        return 20;  
}