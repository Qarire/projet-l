#ifndef _PERSONNAGE_H
#define _PERSONNAGE_H


#include "Vecteur.h"

class Personnage {

private:
    
    int pv;
    Vecteur pos;


public:

    Personnage();
    /** @brief Constructeur par défaut; **/
    Personnage(Vecteur p, int pv);
    /** @brief constructeur par copie **/
    ~Personnage();
    /** @brief Destructeur par défaut **/
    int getpv();


    Vecteur getpos();


    void Update(float dt);
    /** **/

};
#endif
