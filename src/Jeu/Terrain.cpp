#include "Terrain.h"

using namespace std;

Terrain::Terrain() {
    width=0;
    height=0;
}

Terrain::Terrain(unsigned int x, unsigned int y) {
    width = x;
    height = y;
}

Terrain::~Terrain(){
    for(int i = 0; i < personnageList.size(); i++) {
        delete personnageList[i];
    }

    personnageList.clear();
}

unsigned int Terrain::getWidth() const {
    return width;
}

unsigned int Terrain::getHeight() const {
    return height;
}

vector<Personnage*> Terrain::getPersonnageList() const {
    return personnageList;
}
Personnage* Terrain::getPersonnage(unsigned int index) const {
    if(index < 0 || index >= personnageList.size())
        throw std::out_of_range ("index is out of range");

    return personnageList[index];
}


bool Terrain::addPersonnage(Personnage* personnage) {
    personnageList.push_back(personnage);

    return true;
}
bool Terrain::removePersonnage(Personnage* personnage) {
    for(int i = 0; i < personnageList.size(); i++) {
        if(personnageList[i] == personnage) {
            personnageList.erase(personnageList.begin()+i);
            return true;
        }

    }

    return false;
}


bool Terrain::isThereSomethingAt(Vecteur position) const { // TODO use templates to check for the different type of things that can be in there
    for(int i = 0; i < personnageList.size(); i++) {
        if(personnageList[i]->getpos() == position)
            return true;
    }

    return false;
}
Personnage* Terrain::findPersonnageAt(Vecteur position) const {
    if(!isThereSomethingAt(position))
        throw std::invalid_argument("there is nothing at this position");

    for(int i = 0; i < personnageList.size(); i++) {
        if(personnageList[i]->getpos() == position)
            return personnageList[i];
    }
}


void Terrain::Update(float dt) {
    for(int i = 0; i < personnageList.size(); i++) {
        personnageList[i]->Update(dt);
    }
}