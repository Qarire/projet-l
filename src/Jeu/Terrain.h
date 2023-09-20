#pragma once

#include <iostream>
#include <exception>
#include <vector>

#include "Vecteur.h"
#include "Personnage.h"

using namespace std;


enum TEAM {
    BLUE,
    RED
};


class Terrain {

private:
    
    unsigned int height, width; /** @brief les deux dimension du terrain */
    vector<Personnage*> personnageList;
    vector<Personnage*> blueTeam;
    vector<Personnage*> redTeam;

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

    bool addPersonnage(Personnage*, TEAM);
    bool removePersonnage(Personnage*);
    
    TEAM findPersonnageTeam(Personnage*) const ;
    bool inTheSameTeam(Personnage* personnageA, Personnage* personnageB) const;
    vector<Personnage*> getMyTeam(TEAM) const;
    vector<Personnage*> getEnemyTeam(TEAM) const;

    bool isThereSomethingAt(Vecteur position) const; // will use templates
    Personnage* findPersonnageAt(Vecteur position) const; // will use templates


    void cleanDeads();


    void Update(float dt);
};