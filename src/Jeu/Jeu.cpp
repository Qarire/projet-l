#include "Jeu.h"

using namespace std;


// ! Singleton
Jeu* Jeu::instance= nullptr;

void Jeu::Update(float dt) {
    terrain->Update(dt);

    if(terrain->getPersonnageList().size() == 0) {
        terrain->addPersonnage(new Personnage(Vecteur(0, 25), 100, new MovementSimple()), BLUE);
    }
    else if(terrain->getPersonnageList().size() == 1) {
        terrain->addPersonnage(new PunchingBag(Vecteur(45, 25), 100), RED);
    }
}

