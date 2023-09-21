#ifndef _PERSOSORCERER_H
#define _PERSOSORCERER_H
#include "../Personnage.h"
/** la sorcière a la capacité d'augmenter les dégâts causés par son équipe et peut également réduire ceux des ennemis*/
class PersoTank : public Personnage {
    public :
    PersoSorcerer(position, pv) : Personnage(position, pv, new Melee(), new MovementSimple());
    void receiveDamage(int damage) override;
};


#endif