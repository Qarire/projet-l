#ifndef _JEU_H
#define _JEU_H

#include "Terrain.h"
#include "Personnage.h"

class Jeu {

    private:
        Terrain map;
        Personnage player;

    public :

    Jeu();
    /** @brief Constructeur par défaut **/

    ~Jeu();
    /** @brief Destructeur par défaut **/

    Personnage getPersonnage() const;
    /** @brief recupere le Personnage **/

    Terrain getTerrain() const;
    /** @brief recupere le Terrain **/

}

#endif