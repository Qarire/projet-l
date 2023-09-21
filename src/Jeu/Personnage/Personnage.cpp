#include "Personnage.h"


#include <iostream>
using namespace std;

Personnage::Personnage(Vecteur position, int pv, Movement* movement){
    this->position = position;
    this->pv = pv;
    this->movement = movement;

    this->isDead = false;
}

Personnage::~Personnage(){
    delete this->movement;
}



void Personnage::Update(float dt, vector<Personnage*> myTeam, vector<Personnage*> enemyTeam) {
    if(enemyTeam.size() > 0) {
        if(!enemyTeam[0]->getIsDead()) {
            cout << "my position: " << position << " enemy position: " << enemyTeam[0]->getPosition() << endl;
            position = movement->Move(position, enemyTeam[0]->getPosition());
        }
    }
}