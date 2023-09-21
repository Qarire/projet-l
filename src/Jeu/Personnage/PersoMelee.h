#ifndef _PERSOMELEE_H
#define _PERSOMELEE_H
#include "../Personnage.h"
/** le personnage Melee est le plus fort en combat. il a besoin d'être proche pour attaquer l'adversaire.*/
class PersoMelee : public Personnage {
    public :
    PersoMelee(position, pv) : Personnage(position, pv, new Melee(), new MovementSimple());

};

#endif