#pragma once

#ifndef _ASTAR_H
#define _ASTAR_H


#define colone 9; // pour l'instant déclarer à l'arrache mais provient de qqpart où cest def
#define ligne 9;



#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include "Case.h"
using namespace std;



class Astar : public Movement{
public:
    Astar(int heightTerrain, int widthTerrain) : Movement(heightTerrain, widthTerrain) {}
    
    int Heuristic(Vecteur start, Vecteur objective);//ok
    int fscore(Case case1);//ok

    
    //bool case_valide(Vecteur case1);
    bool destination(Vecteur depart, Vecteur arrive);
    vector<Case*> case_autour(vector<vector<Case*>> TAB,Case case1, Vecteur dest);
    int min_f_score( vector<Case*> tab); //ok
    bool appartient_list(Case* case1, vector<Case*> OPEN);
    vector<Vecteur> defilement (Case* case1);
    vector<Vecteur> algo_Astar(vector<Vecteur> TAB, Vecteur depart, Vecteur objectif);
    Vecteur Move(Vecteur start, Vecteur objective) override;
};


#endif