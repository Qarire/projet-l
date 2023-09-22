#include "Range.h"
#include "Personnage.h"
#include <iostream>
using namespace std;
/** l'archer a la capacité d'attaquer de loin les ennemis*/
class PersoArcher : public Personnage {
    public :
    PersoArcher(Vecteur position, int pv, Movement* movement) : Personnage(position, pv, new Range(), movement) {}
};


