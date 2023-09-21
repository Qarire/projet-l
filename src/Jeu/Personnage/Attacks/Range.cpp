#include "Range.cpp"

bool Range::canTouch(Vecteur myPosition, Vecteur targetPosition) {
    diffX = abs(myPosition.x - targetPosition.x);
    diffY = abs(myPosition.y - targetPosition.y);

    if(diffX >= 3 || diff >=3)
        return true;
    return false;
}

vector<Vecteur> Range::findAllPositionWhereIcanHit(Vecteur targetPosition) {
    vector<Vecteur> positionList;

    int height = Jeu::getInstance()->getTerrain()->getHeight();
    int width = Jeu::getInstance()->getTerrain()->getWidth();

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(canTouch(Vecteur(y, x), targetPosition))
                positionList.push_back(Vecteur(y, x));
        }
    }

    return positionList;
}

int Range::damage(Vecteur myPosition, Vecteur targetPosition) {
    diffX = abs(myPosition.x - targetPosition.x);
    diffY = abs(myPosition.y - targetPosition.y);

    real_dist = diffX + diffY;

    if (real_dist <= 5) {
        return 5;
    } else if (real dist > 8) {
        return 10;  
    }else 
        return 20;  
}