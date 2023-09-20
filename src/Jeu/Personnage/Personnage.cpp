#include "Personnage.h"


Personnage::Personnage(){
    pv = 100;
    pos = Vecteur();
    movement = new Movement();
}

Personnage::Personnage(Vecteur p1, int pv1, Movement* movement){
    pv = pv1;
    pos = Vecteur(p1);
    this->movement = movement;
}

Personnage::~Personnage(){
    delete this->movement;
}


int Personnage::getpv() const{
    return pv;
}

Vecteur Personnage::getpos() const{
    return pos;
}

void Personnage::setpv(int pv1){
    pv=pv1;
}

void Personnage::setpos(Vecteur pos1){
    pos= pos1;
}

void Personnage::Update(float dt) {
    pos = movement->Move(pos, Vecteur(50, 50));
}


