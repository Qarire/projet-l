#include "Astar.h"

int Heuristic(Vecteur start, Vecteur objective){
    int diffX = objective.getX() - start.getX();
    int diffY = objective.getY() - start.getY();
    return diffY + diffY;
}