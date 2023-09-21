#pragma once

#include "Personnage.h"

class PunchingBag : public Personnage {
public:
    PunchingBag(Vecteur position, int pv) : Personnage(position, pv, new Movement()) {}
    /** @brief constructeur**/
};