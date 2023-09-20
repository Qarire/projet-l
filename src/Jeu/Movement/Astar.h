#pragma once

#include "Movement.h"


class Astar : public Movement{
public:
    int Heuristic(Vecteur start, Vecteur objective);
    int gscore(Vecteur parent, Vecteur v);
    int fscore(int heuristic, int gscore);

    Vecteur Move(Vecteur start, Vecteur objective) override;
};