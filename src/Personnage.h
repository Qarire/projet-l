#ifndef _PERSONNAGE_H
#define _PERSONNAGE_H


#include "Vecteur.h"

class Personnage {

private:
    
    int pv;
    Vecteur pos;
    Movement* movement;


public:

    Perso();
    /** @brief Constructeur par défaut; **/
    Perso(Vecteur p, int pv);
    /** @brief constructeur par copie **/
    ~Perso(Vecteur p, int pv);
    /** @brief Destructeur par défaut **/
    int getpv();


    Vecteur getpos();


    Perso(float dt);
    /** **/

}
#endif
