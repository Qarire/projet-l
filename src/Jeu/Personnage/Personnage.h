#pragma once

#include "Vecteur.h"
#include "MovementSimple.h"


class Personnage {

private:
    
    int pv;
    Vecteur pos;
    Movement* movement;


public:

    Personnage();
    /** @brief Constructeur par défaut; **/
    Personnage(Vecteur p, int pv, Movement* movement);
    /** @brief constructeur par copie **/
    ~Personnage();
    /** @brief Destructeur par défaut **/

    int getpv() const;
    /** @brief Recupere les pv d'un personnage**/

    Vecteur getpos() const;
    /** @brief  Recupere la position d'un personnage**/

    void setpv(int pv1);
    /** @brief  definit les pv d'un personnage**/

    void setpos(Vecteur pos1);
    /** @brief  definit la position d'un personnage**/

    void Update(float dt);
    /** **/



    //+
    //-
};