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


void Personnage::receiveDamage(int damage, bool isAttacked) {
    int pvInit = this->pv;
    if (isAttacked==true){
        pv-= damage;
    }
    else if (isAttacked == false && pv < pvInit) {
        pv+=damage;
    }
    if (pv>pvInit) 
        pv=pvInit;
    if(pv <= 0)
        kill();
}



void Personnage::Update(float dt, vector<Personnage*> myTeam, vector<Personnage*> enemyTeam) {
    if(enemyTeam.size() > 0) {
        if(!enemyTeam[0]->getIsDead()) {
            if(attack->canTouch(position, enemyTeam[0]->getPosition())) {
                enemyTeam[0]->receiveDamage(attack->damage(position, enemyTeam[0]->getPosition()),true);
                cout << attack->damage(position, enemyTeam[0]->getPosition()) << endl;
            }
            else {
                vector<Vecteur> positionList = attack->findAllPositionWhereIcanHit(
                    enemyTeam[0]->getPosition(), 
                    movement->getHeight(), 
                    movement->getWidth()
                );
                
                cout << "Myposition : " << position << " enemy position: " << enemyTeam[0]->position << " target position " << positionList[0] << endl;
                for(int i = 0; i < positionList.size(); i++) {
                    cout << " - " << positionList[i] << endl;
                }


                position = movement->Move(position, positionList[0]);
            }
        }
    }
}