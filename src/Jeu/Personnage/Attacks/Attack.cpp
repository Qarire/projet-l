#include "Attack.h"


vector<Vecteur> Attack::findAllPositionWhereIcanHit(Vecteur targetPosition, int heightTerrain, int widthTerrain) {
    vector<Vecteur> positionList;


    for(int y = 0; y < heightTerrain; y++) {
        for(int x = 0; x < widthTerrain; x++) {
            if(canTouch(Vecteur(y, x), targetPosition))
                positionList.push_back(Vecteur(y, x));
        }
    }

    return positionList;
}