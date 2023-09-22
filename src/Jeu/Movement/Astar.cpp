#include "Astar.h"

#define colone 9; // pour l'instant déclarer à l'arrache mais provient de terrain
#define ligne 9;



int Heuristic(Vecteur start, Vecteur objective){
    int diffX = objective.Vecteur.getX() - start.Vecteur.getX();
    int diffY = objective.Vecteur.getY() - start.Vecteur.getY();
    return diffY + diffY;
}

int gscore(Case case1 ){
    return *(case1.parent).g_score +1;
}
    
int fscore(Case case1){
    return case1.g_score + case1.h_score;
}

/*bool case_valide(Vecteur case1){
        return (case1.getx()>=0)&&(case1.gety()>=0)&&(case1.getx()<colone)&&(case1.gety()<ligne);
    }*/ // on considerre pour l'intsant que chaque case est accessible independamment de la position des ennemis

bool destination(Vecteur depart, Vecteur arrive){
    return (depart.getx() == arrive.getx())&&(depart.gety() == arrive.gety());
}

vector<*Case> case_autour(vector<vector<Case*>> TAB,Case case){
    vector<*Case> liste;
    for(i=-1; i<2; i++){
        for(j=-1; j <2;j++){
            TAB[i][j].parent = &case;
            liste.append(TAB[i][j]);
        }
int min_f_score( vector<Case*> TAB){
    float mini = TAB.begin().f_score;
    int j=0;
    for(int i = 1; i< TAB.size();i++){
        if ((mini)< TAB[i].f_score){
            mini= TAB[i].f_score;
            j= i;
        }
    }
    return j;
}

bool appartient_list(Case* case1, vector<Case*> liste){
    for (i = 0 ; i<liste.size(); i++){
        if (case1== liste[i] ){
            return i;
        }
    }
    return -1;
}

vector<Vecteur> defilement (Case case1){
    vector<Vecteur> l = [];
    case* p =&case1;
    while(p §= nullptr){
        l.append(case1.Vecteur);
        p = case1.parent;
    }
    return l;
}

vector<Vecteur> astar (vector<Vecteur> TAB, Vecteur depart, Vecteur objectif){
    //init le tab qui permet d'acceder a la position des obstacles directment 
    vector<vector<Case*>> TAB;
    for (int i =0 ; i< colone ; i++){
        for (int j =0 ; j< colone ; j++){
            TAB[i][j]=(TAB[i][j].vecteur = Vecteur.setx(i);
                        TAB[i][j].vecteur = Vecteur.sety(j);
                        TAB[i][j].parent = nullptr;
                        TAB[i][j] .f_score = MAX;
                        TAB[i][j].h_score = MAX;
                        TAB[i][j].g_score = MAX;
                        )
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
        Case p = OPEN[min_f_score(OPEN)];
        OPEN.remove(p)
        
        vector<Case*> succesor = case_autour(TAB,OPEN);
        for (k=0; k< 8k++){
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
    for(i=0; i<colone; i++){
        for(j=0; j <ligne;j++){
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

    return astar(TAB,start,destination).begin();
}
