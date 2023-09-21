#include "Terrain.h"


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


bool Terrain::addPersonnage(Personnage* personnage, TEAM team) {
    if(team == BLUE)
        blueTeam.push_back(personnage);
    else
        redTeam.push_back(personnage);
    
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

TEAM Terrain::findPersonnageTeam(Personnage* personnage) const {
    for(int i = 0; i < blueTeam.size(); i++) {
        if(blueTeam[i] == personnage)
            return BLUE;
    }
    for(int i = 0; i < redTeam.size(); i++) {
        if(redTeam[i] == personnage)
            return RED;
    }

    throw std::invalid_argument("this Personnage is not in any team");
}
bool Terrain::inTheSameTeam(Personnage* personnageA, Personnage* personnageB) const {
    return findPersonnageTeam(personnageA) == findPersonnageTeam(personnageB);
}
vector<Personnage*> Terrain::getMyTeam(TEAM team) const {
    if(team == BLUE)
        return blueTeam;
    else
        return redTeam;
}
vector<Personnage*> Terrain::getEnemyTeam(TEAM team) const {
    if(team == BLUE)
        return redTeam;
    else
        return blueTeam;
}



bool Terrain::isThereSomethingAt(Vecteur position) const { // TODO use templates to check for the different type of things that can be in there
    for(int i = 0; i < personnageList.size(); i++) {
        if(personnageList[i]->getPosition() == position)
            return true;
    }

    return false;
}
Personnage* Terrain::findPersonnageAt(Vecteur position) const {
    for(int i = 0; i < personnageList.size(); i++) {
        if(personnageList[i]->getPosition() == position)
            return personnageList[i];
    }

    throw std::invalid_argument("there is nothing at this position");
}


void Terrain::cleanDeads() {
    for(int i = 0; i < personnageList.size(); i++) {
        if(personnageList[i]->getIsDead()) {
            removePersonnage(personnageList[i]);
            cleanDeads();
            return;
        }   
    }
}



void Terrain::Update(float dt) {
    for(int i = 0; i < personnageList.size(); i++) {
        TEAM team = findPersonnageTeam(personnageList[i]);
        personnageList[i]->Update(dt, getMyTeam(team), getEnemyTeam(team));
    }
}