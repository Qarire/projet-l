#include "Astar.h"



/*Case::Case(Vecteur pos1, int toA, int toB, int total, Case* parent, bool traversable, char name) {
	//Vecteur pos = pos1 ;
    set_f_score(total);
    float h_score= toA;
    float g_score =toB;

    //Case* parent;
}

Case::~Case() {}*/

int Heuristic(Vecteur start, Vecteur objective){
    int diffX = objective.getX() - start.getX();
    int diffY = objective.getY() - start.getY();
    return diffY + diffY;
}

    
int fscore(Case case1){
    return case1.g_score + case1.h_score;
}

/*bool case_valide(Vecteur case1){
        return (case1.getx()>=0)&&(case1.gety()>=0)&&(case1.getx()<colone)&&(case1.gety()<ligne);
    }*/ // on considerre pour l'intsant que chaque case est accessible independamment de la position des ennemis

bool destination(Vecteur depart, Vecteur arrive){
    return (depart.getX() == arrive.getX())&&(depart.getY() == arrive.getY());
}

vector<Case*> case_autour(vector<vector<Case*>> TAB,Case case1,Vecteur arrive){
    vector<Case*> liste;
    for(int i=-1; i<2; i++){
        for(int j=-1; j <2;j++){
            TAB[i][j]->parent = &case1;
            liste.push_back(TAB[i][j]);
            TAB[i][j]->h_score = Heuristic(TAB[i][j]->pos,arrive)
            if(abs(i)+abs(j)==2){
                TAB[i][j]->g_score = TAB[i][j]->parent->g_score +1.41;
            }
            else{
                TAB[i][j]->g_score = TAB[i][j]->parent->g_score +1;
            }
        }
    }
    return liste;
}


int min_f_score( vector<Case*> TAB){
    float mini = TAB.begin()->f_score;
    int j=0;
    for(int i = 1; i< TAB.size();i++){
        if ((mini)< TAB[i]->f_score){
            mini= TAB[i]->f_score;
            j= i;
        }
    }
    return j;
}

bool appartient_list(Case* case1, vector<Case*> liste){
    for (int i = 0 ; i<liste.size(); i++){
        if (case1== liste[i] ){
            return i;
        }
    }
    return -1;
}

vector<Vecteur> defilement (Case case1){
    vector<Vecteur> l;
    Case* p =&case1;
    while(p != nullptr){
        l.push_back(case1.pos);
        p = case1.parent;
    }
    return l;
}

vector<Vecteur> astar_ (vector<Vecteur> TAB, Vecteur depart, Vecteur objectif){
    for (int i =0 ; i< MAX ; i++){// modif apres en fonction de la tailled efield
        for (int j =0 ; j< MAX ; j++){
            TAB[i][j].pos = Vecteur.setX(i);
            TAB[i][j].pos = Vecteur.setY(j);
            TAB[i][j].parent = nullptr;
            TAB[i][j] .f_score = MAX;
            TAB[i][j].h_score = MAX;
            TAB[i][j].g_score = MAX;
                        
        }
    }
    /*for (int i =0; i< obstacle_perso.size(); i++){
        TAB[obstacle_perso[i].Vecteur.getx()][obstacle_perso[i].Vecteur.gety()]=1;
    }*/

    vector<Case*> OPEN;
    vector<Case*> CLOSE;

    Case debut;
    debut.vecteur = depart;
    debut.parent = nullptr;
    debut .f_score = 0;
    debut.h_score = Heuristic(depart,objectif);
    debut.g_score = 0;


    OPEN.insert(debut);
    
    while (!OPEN.empty()){
        int i_min_f = min_f_score(OPEN);
        Case p = OPEN[i_min_f];
        OPEN.erase(i_min_f);
        
        vector<Case*> succesor = case_autour(TAB,OPEN,objectif);
        for (int k=0; k< 8;k++){
            if (destination(succesor[k].Vecteur,objectif)){
                return defilement (succesor[k]);
            }
      
            int pos_closed = appartient_list(succesor[k],CLOSED);
            if(pos_open >=0 && succesor[k].f_score < OPEN[pos_open].f_score){
                OPEN[pos_open] = succesor[k];
            }

            if(pos_closed >=0 && succesor[k].f_score < CLOSED[pos_open].f_score){
                OPEN.append(CLOSED[pos_closed]);
                CLOSED[pos_closed] = succesor[k];

            }
            

        }
        CLOSED.append(p);
    }
    float mini = TAB[0][0].f_score;
    int i_save=0;
    int j_save = 0;
    for(int i=0; i<colone; i++){
        for(int j=0; j <ligne;j++){
            if ((mini)< TAB[i][j].f_score){
                mini= TAB[i][j].f_score;
                i_save= i;
                j_save= j;
            }
        }
    }
    
    return defilement (TAB[i_save][j_save]);// cas si case final blocké par obstacle case avec le plus petit f devient la new destination (et on a deja calculer f)
}






Vecteur Move(Vecteur start, Vecteur destination){
    vector<Vecteur> TAB; //init avec les obsatcle recuperr a un moment
    return astar_(TAB,start,destination).begin();
}
