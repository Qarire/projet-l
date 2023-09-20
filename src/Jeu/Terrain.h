#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <iostream>
#include <exception>
#include <vector>

#include "Vecteur.h"
#include "Personnage.h"

using namespace std;

class Terrain {

private:
    
    unsigned int height, width; /** @brief les deux dimension du terrain */
    vector<Personnage*> personnageList;

public:

    Terrain();
    /** @brief Constructeur par défaut; **/
    
    Terrain(unsigned int x, unsigned int y);
    /** @brief Constructeur par copie */
    
    ~Terrain();
    /** @brief Destructeur par défaut **/

    unsigned int getWidth() const;
    /** @brief Recupere la dimension x du Terrain **/

    unsigned int getHeight() const;
    /** @brief Recupere la dimension du y du Terrain **/

    vector<Personnage*> getPersonnageList() const;
    /** @brief recupere le Personnage **/

    Personnage* getPersonnage(unsigned int) const;


    bool addPersonnage(Personnage*);
    bool removePersonnage(Personnage*);

    bool isThereSomethingAt(Vecteur position) const;
    Personnage* findPersonnageAt(Vecteur position) const;

    void Update(float dt);

};
#endif
