#ifndef _PERSOSORCERER_H
#define _PERSOSORCERER_H
#include "Personnage.h"
/** la sorcière a la capacité d'augmenter les dégâts causés par son équipe et peut également réduire ceux des ennemis*/
class PersoSorcerer : public Personnage {
public :
    PersoSorcerer(Vecteur position, int pv, Movement* movement) : Personnage(position, pv, new Melee(), movement) { this->pv = pv/1.5; }
    void receiveDamage(int damage) override;
};


#endif