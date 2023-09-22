#ifndef _ASTAR_H
#define _ASTAR_H

#include <vector>
#include "Movement.h"

class Case {
private : 
    Vecteur pos;
    float f_score;
    float h_score;
    float g_score;

    Case* parent;

public : 
    //bool case_valide(Vecteur case1);
    bool destination(Vecteur depart, Vecteur arrive);
    vector<*Case> case_autour(Case case);
    float get_f_score();
    void set_f_score();

    float get_g_score();
    void set_f_score();

    float get_h_score();
    void set_f_score();

    Case* get_parent();
    void set_parent();
}

class Astar : public Movement{
public:
    int Heuristic(Vecteur start, Vecteur objective);//ok
    int gscore(Case case1);//ok
    int fscore(Case case1);//ok

    int min_f( vector<Case*> TAB); //ok
    vector<Vecteur> astar(list obstacle_perso, Vecteur depart, Vecteur objectif);
    Vecteur Move(Vecteur start, Vecteur objective) override;
    bool appartient_list(Case* case, vector<Case*> OPEN);
    vector<Vecteur> defilement (Case case1);
};


#endif