#ifndef _PERSOTANK_H
#define _PERSOTANK_H
#include "Personnage.h"

/** git checkout ft/move-perso 
 un tank est un personnage qui possède plus de pv que les autres et qui peut donc recevoir plus de dégâts avec une bien meilleure survavibilité*/
class PersoTank : public Personnage {
public :
    PersoTank(Vecteur position, int pv, Movement* movement) : Personnage(position, pv, new Melee(), movement) {this->pv = pv*2;}
    void receiveDamage(int damage) override;
};









#endif