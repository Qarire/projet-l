#ifndef _ASTAR_H
#define _ASTAR_H


#define colone 9; // pour l'instant déclarer à l'arrache mais provient de terrain
#define ligne 9;



#include <vector>
#include <cmath>
#include "Movement.h"
using namespace std;


class Case {
private : 
    Vecteur pos;
    float f_score;
    float h_score;
    float g_score;

    Case* parent;

public : 
    Case(Vecteur v=Vecteur(0,0), float = 0, float = 0, float = 0, Case* = nullptr);
	~Case();
    float get_f_score();
    float get_g_score();
    float get_h_score();
    Vecteur get_pos();
    Case* get_parent();


    void set_f_score();
    void set_g_score();
    void set_h_score();

    //bool case_valide(Vecteur case1);
    bool destination(Vecteur depart, Vecteur arrive);
    vector<Case*> case_autour(Case case1);
    
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
};


#endif