#include "Attack.h"


vector<Position> Attack::findAllPositionWhereIcanHit(Position targetPosition, int heightTerrain, int widthTerrain) {
    vector<Position> positionList;


    for(int y = 0; y < heightTerrain; y++) {
        for(int x = 0; x < widthTerrain; x++) {
            if(canTouch(Position(y, x), targetPosition))
                positionList.push_back(Position(y, x));
        }
    }

    return positionList;
}