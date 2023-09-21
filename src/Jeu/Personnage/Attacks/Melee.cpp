#include "Melee.h"


bool Melee::canTouch(Vecteur myPosition, Vecteur targetPosition) {
    diffX = abs(myPosition.x - targetPosition.x);
    diffY = abs(myPosition.y - targetPosition.y);

    if(diffX <= 1 && diffY <= 1)
        return true;
    return false;
}
vector<Vecteur> Melee::findAllPositionWhereIcanHit(Vecteur targetPosition) {
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
int Melee::damage(Vecteur myPosition, Vecteur targetPosition) {

    return 20;
}