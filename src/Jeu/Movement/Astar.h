#ifndef _ASTAR_H
#define _ASTAR_H


#define colone 9; // pour l'instant déclarer à l'arrache mais provient de qqpart où cest def
#define ligne 9;



#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include "Movement.h"
using namespace std;


class Case {
private : 
    Vecteur pos;
    float f_score;
    float h_score;
    float g_score;
    bool accessible;
    Case* parent;

public : 
    Case(Vecteur =Vecteur(0,0), float = 0, float = 0, float = 0, Case* = nullptr);
	~Case();
    float get_f_score();
    float get_g_score();
    float get_h_score();
    Vecteur get_pos();
    Case* get_parent();
    bool get_accessible();


    void set_f_score(float x);
    void set_g_score(float x);
    void set_h_score(float x);
    void set_parent( Case* case1);
    void set_pos(Vecteur v);
    void set_accessible(bool b);

    
    
};

class Astar : public Movement{
public:
    int Heuristic(Vecteur start, Vecteur objective);//ok
    int fscore(Case case1);//ok

    int min_f( vector<Case*> TAB); //ok
    vector<Vecteur> astar_(vector<Vecteur> TAB, Vecteur depart, Vecteur objectif);
    Vecteur Move(Vecteur start, Vecteur objective) override;
    bool appartient_list(Case case1, vector<Case*> OPEN);
    vector<Vecteur> defilement (Case case1);
    //bool case_valide(Vecteur case1);
    bool destination(Vecteur depart, Vecteur arrive);
    vector<Case*> case_autour(Case case1);
};


#endif