#ifndef _JEU_H
#define _JEU_H

#include "Terrain.h"
#include "Personnage.h"


using namespace std;

class Jeu {
private:

    // ! Singleton
    static Jeu* instance;

    Jeu() { terrain = new Terrain(50,50); }
    // ! Singleton

    Terrain* terrain;

public:

    // ! Singleton
    static Jeu* getInstance() {
        if(instance==nullptr){
            instance = new Jeu();
        }
        return instance;
    }    

    
    ~Jeu() { delete terrain; }
    /** @brief Destructeur par défaut **/

    Terrain* getTerrain() const { return terrain; }
    /** @brief recupere le Terrain **/


    void Update(float dt);

};

#endif