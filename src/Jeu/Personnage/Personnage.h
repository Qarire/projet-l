#pragma once

#include <vector>
#include "Vecteur.h"
#include "MovementSimple.h"

using namespace std;


class Personnage {

protected:
    int pv;
    Vecteur position;
    Movement* movement;

    bool isDead;

public:
    Personnage(Vecteur position, int pv, Movement* movement);
    /** @brief constructeur**/
    ~Personnage();
    /** @brief Destructeur par défaut **/

    int getPv() const { return pv; }
    /** @brief Recupere les pv d'un personnage**/
    void setPv(int pv) { this->pv = pv; }
    /** @brief  definit les pv d'un personnage**/

    Vecteur getPosition() const { return position; }
    /** @brief  Recupere la position d'un personnage**/
    void setPosition(Vecteur position) { this->position = position; }
    /** @brief  definit la position d'un personnage**/

    bool getIsDead() const { return isDead; }
    void kill() { isDead = true; }


    void Update(float dt, vector<Personnage*> myTeam, vector<Personnage*> enemyTeam);
};