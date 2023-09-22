#include "Personnage.h"
#include <iostream>
using namespace std;

/** le personnage Melee est le plus fort en combat. il a besoin d'être proche pour attaquer l'adversaire.*/
class PersoMelee : public Personnage {
    public :
    PersoMelee(Vecteur position, int pv, Movement* movement) : Personnage(position, pv, new Melee(), movement) {}

};
