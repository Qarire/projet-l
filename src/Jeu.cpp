#include "Jeu.h"

using namespace std;


Jeu::Jeu() {

    map = Terrain(50,50);
    player.push_back(Personnage(Vecteur(),100));

}

Jeu::~Jeu() {


}

vector<Personnage> Jeu::getPersonnage() const {

    return player;
}

Terrain Jeu::getTerrain() const {

    return map;
}

