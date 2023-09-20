#ifndef _JEU_H
#define _JEU_H

#include "Terrain.h"
#include "Personnage.h"


using namespace std;

class Jeu {

    private:
        Terrain* terrain;

    public :

    Jeu();
    /** @brief Constructeur par défaut **/
    
    
    ~Jeu();
    /** @brief Destructeur par défaut **/

    Terrain* getTerrain() const;
    /** @brief recupere le Terrain **/

    void Update(float dt);

};

#endif