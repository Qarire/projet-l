#include "displayer.h"


// ! Singleton
Displayer* Displayer::instance= nullptr;

void Displayer::Display() const {

    Jeu* jeu = Jeu::getInstance();

    for(int y = 0; y < jeu->getTerrain()->getHeight(); y++) {
        cout << "| ";

        for(int x = 0; x < jeu->getTerrain()->getWidth(); x++) {
            if(jeu->getTerrain()->isThereSomethingAt(Vecteur(x, y))) {
                Personnage* personnage = jeu->getTerrain()->findPersonnageAt(Vecteur(x, y));
                cout << "P ";
            }
            else
                cout << ". ";
        }

        cout << "|\n";
    }

    cout << endl;
}