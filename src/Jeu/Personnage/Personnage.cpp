#include "Personnage.h"


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
            position = movement->Move(position, enemyTeam[0]->getPosition());
        }
    }
}