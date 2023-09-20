#include "Jeu.h"

using namespace std;


Jeu::Jeu() {
    terrain = new Terrain(50,50);
}

Jeu::~Jeu() {
    delete terrain;
}

Terrain* Jeu::getTerrain() const {

    return terrain;
}


void Jeu::Update(float dt) {
    terrain->Update(dt);

    if(terrain->getPersonnageList().size() == 0) {
        terrain->addPersonnage(new Personnage(Vecteur(25, 25), 100, new MovementSimple()));
    }
}

