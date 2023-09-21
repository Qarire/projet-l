#ifndef _PERSOARCHER_H
#define _PERSOARCHER_H
#include "Personnage.h"
/** l'archer a la capacité d'attaquer de loin les ennemis*/
class PersoArcher : public Personnage {
    public :
    PersoArcher(position, pv) : Personnage(position, pv, new Melee(), new MovementSimple());
    void receiveDamage(int damage) override;
};



#endif