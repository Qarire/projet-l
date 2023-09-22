#include "Jeu.h"

using namespace std;


// ! Singleton
Jeu* Jeu::instance= nullptr;

void Jeu::Update(float dt) {
    terrain->Update(dt);
    terrain->cleanDeads();

    if(terrain->getPersonnageList().size() == 0) {
        terrain->addPersonnage(new Personnage(Vecteur(0, 25), 1000, new Melee(), new MovementSimple(terrain->getHeight(), terrain->getWidth())), BLUE);
    }
    else if(terrain->getPersonnageList().size() == 1) {
        terrain->addPersonnage(new Personnage(Vecteur(49, 25), 1000, new Range(), new MovementSimple(terrain->getHeight(), terrain->getWidth())), RED);
    }
}

