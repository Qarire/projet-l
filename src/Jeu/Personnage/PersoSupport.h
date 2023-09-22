#ifndef _PERSOSUPPORT_H
#define _PERSOSUPPORT_H
#include "Range.h"
#include "Personnage.h"

/** le support permet de regénérer les pv de son équipe*/
class PersoSupport : public Personnage {
public :
    PersoSupport(Vecteur position, int pv, Movement* movement) : Personnage(position, pv, new Range(), movement) { this->pv = pv*2; }
    void receiveDamage(int damage, bool isAttacked=true) override;
};


#endif