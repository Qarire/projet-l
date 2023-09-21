#include "Personnage.h"


#include <iostream>
using namespace std;

Personnage::Personnage(Vecteur position, int pv, Attack* attack, Movement* movement){
    this->position = position;
    this->pv = pv;

    this->attack = attack;
    this->movement = movement;

    this->isDead = false;
}

Personnage::~Personnage(){
    delete this->movement;
}


void Personnage::receiveDamage(int damage) {
    pv-= damage;

    if(pv <= 0)
        kill();
}


void Personnage::Update(float dt, vector<Personnage*> myTeam, vector<Personnage*> enemyTeam) {
    if(enemyTeam.size() > 0) {
        if(!enemyTeam[0]->getIsDead()) {
            if(attack->canTouch(enemyTeam[0]))
                enemyTeam[0]->receiveDamage(attack->damage());
            else {
                vector<Vecteur> positionList = attack->findAllPositionWhereIcanHit(enemyTeam[0]->getPosition());
                
                position = movement->Move(position, positionList[0]);
            }

        }
    }
}