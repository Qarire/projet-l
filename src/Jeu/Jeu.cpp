#include "Jeu.h"

using namespace std;


// ! Singleton
Jeu* Jeu::instance= nullptr;

void Jeu::Update(float dt) {
    terrain->Update(dt);

    if(terrain->getPersonnageList().size() == 0) {
        terrain->addPersonnage(new Personnage(Vecteur(0, 0), 100, new MovementSimple()), BLUE);
    }
    else if(terrain->getPersonnageList().size() == 1) {
        terrain->addPersonnage(new Personnage(Vecteur(49, 49), 100, new MovementSimple()), RED);
    }
}

