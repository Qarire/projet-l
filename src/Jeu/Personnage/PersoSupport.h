#ifndef _PERSOSUPPORT_H
#define _PERSOSUPPORT_H
#include "../Personnage.h"
/** le support permet de regénérer les pv de son équipe*/
class PersoSupport : public Personnage {
    public :
    PersoSupport(position, pv) : Personnage(position, pv, new Melee(), new MovementSimple());
    void receiveDamage(int damage) override;
};


#endif