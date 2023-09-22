#ifndef _PERSOARCHER_H
#define _PERSOARCHER_H
#include "Range.h"
#include "Personnage.h"
/** l'archer a la capacité d'attaquer de loin les ennemis*/
class PersoArcher : public Personnage {
    public :
    PersoArcher(Vecteur position, int pv, Movement* movement) : Personnage(position, pv, new Range(), movement) {}
};



#endif