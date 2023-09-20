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



void Personnage::Update(float dt) {
    position = movement->Move(position, Vecteur(50, 50));
}