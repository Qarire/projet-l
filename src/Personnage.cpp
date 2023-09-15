
#include "Personnage.h"



Personnage::Personnage(){
    pv = 100;
    pos = Vecteur();

}

Personnage::Personnage(Vecteur p1, int pv1){
    pv = pv1;
    pos = Vecteur(p1);

}

Personnage::~Personnage(){

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

