#include "displayer.h"

void Displayer::Display() const {

    for(int y = 0; y < terrain->getHeight(); y++) {
        cout << "| ";

        for(int x = 0; x < terrain->getWidth(); x++) {
            if(terrain->isThereSomethingAt(Vecteur(x, y))) {
                Personnage* personnage = terrain->findPersonnageAt(Vecteur(x, y));
                cout << "P ";
            }
            else
                cout << ". ";
        }

        cout << "|\n";
    }

    cout << endl;
}