#include "Astar.h"
const int MAX =100000;
const int COLONNE =100000;
const int LIGNE =100000;




float Case::get_f_score(){
    return this->f_score;
}
float Case::get_g_score(){
    return this->g_score;
}
float Case::get_h_score(){
    return this->h_score;
}
Vecteur Case::get_pos(){
    return this->pos;
}
Case* Case::get_parent(){
    return this->parent;
}
bool Case::get_accessible(){
    return this->accessible;
}

void Case::set_f_score( float x){
    this->f_score = x;
}
void Case::set_g_score( float x){
    this->g_score = x;
}
void Case::set_h_score(float x){
    this->h_score = x;
}
void Case::set_parent( Case* case1){
    this->parent = case1;
}
void Case::set_pos(Vecteur v){
    this->pos = v;
}
void Case::set_accessible(bool b){
    this->accessible = b;
}


int Heuristic(Vecteur start, Vecteur objective){
    int diffX = objective.getX() - start.getX();
    int diffY = objective.getY() - start.getY();
    return diffY + diffY;
}
    
int fscore(Case case1){
    return case1.get_g_score() + case1.get_h_score();
}

/*bool case_valide(Vecteur case1){
        return (case1.getx()>=0)&&(case1.gety()>=0)&&(case1.getx()<colone)&&(case1.gety()<ligne);
    }*/ // on considere pour l'intsant que chaque case est accessible independamment de la position des ennemis

bool destination(Vecteur depart, Vecteur arrive){
    return (depart.getX() == arrive.getX())&&(depart.getY() == arrive.getY());
}

vector<Case*> case_autour(vector<vector<Case*>> TAB,Case case1,Vecteur arrive){
    vector<Case*> liste;
    for(int i=-1; i<2; i++){
        for(int j=-1; j <2;j++){
            if(TAB[i][j]->get_accessible()== true){
                TAB[i][j]->set_parent(&case1) ;
                liste.push_back(TAB[i][j]);
                TAB[i][j]->set_h_score(Heuristic(TAB[i][j]->get_pos(),arrive));
                if((abs(i)+abs(j))==2){
                    TAB[i][j]->set_g_score(TAB[i][j]->get_parent()->get_g_score() +1.41);
                }
                else{
                    TAB[i][j]->set_g_score(TAB[i][j]->get_parent()->get_g_score() +1);
                }
            }
        }
    }
    return liste;
}


int min_f_score( vector<Case*> tab){
    float mini = tab[0]->get_f_score();
    int j=0;
    for(int i = 1; i< tab.size();i++){
        if ((mini)< tab[i]->get_f_score()){
            mini= tab[i]->get_f_score();
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

vector<Vecteur> defilement (Case* case1){
    vector<Vecteur> liste;
    Case* p =case1;
    while(p != nullptr){
        liste.push_back(case1->get_pos());
        p = case1->get_parent();
        printf("hqrhr");


    }
    return liste;
}

vector<Vecteur> astar_ (vector<Vecteur> tabl_obstacle, Vecteur depart, Vecteur objectif){
    vector<vector<Case*>> TAB;
    for (int i =0 ; i< COLONNE ; i++){// modif apres en fonction de la tailled efield
        for (int j =0 ; j< LIGNE ; j++){
            TAB[i][j]->get_pos().setX(i) ;
            TAB[i][j]->get_pos().setX(j);
            TAB[i][j]->set_parent(nullptr);
            TAB[i][j] ->set_f_score(MAX);
            TAB[i][j]->set_h_score(MAX) ;
            TAB[i][j]->set_g_score(MAX) ;
            TAB[i][j]->set_accessible(true) ;
                        
        }
    }
    for (int i =0; i< tabl_obstacle.size(); i++){
        TAB[tabl_obstacle[i].getX()][tabl_obstacle[i].getY()] ->set_accessible(true) ;
    }

    vector<Case*> OPEN;
    vector<Case*> CLOSED;

    Case debut;
    debut.set_pos(depart);
    debut.set_parent(nullptr);
    debut .set_f_score(0);
    debut.set_h_score(Heuristic(depart,objectif)) ;
    debut.set_g_score(0);
    debut.set_accessible(true);

    OPEN.push_back(&debut);
    
    while (!OPEN.empty()){
        int i_min_f = min_f_score(OPEN);
        Case* p = OPEN[i_min_f];
        OPEN.erase(OPEN.begin()+i_min_f);
        
        vector<Case*> succesor = case_autour(TAB,*p,objectif);
        for (int k=0; k< 8;k++){
            if (destination(succesor[k]->get_pos(),objectif)){
                return defilement (succesor[k]);
            }
      
            int pos_closed = appartient_list(succesor[k],CLOSED);
            int pos_open = appartient_list(succesor[k],OPEN);
            if(pos_open >=0 && succesor[k]->get_f_score() < OPEN[pos_open]->get_f_score()){
                OPEN[pos_open] = succesor[k];
            }

            if(pos_closed >=0 && succesor[k]->get_f_score() < CLOSED[pos_open]->get_f_score()){
                OPEN.push_back(CLOSED[pos_closed]);
                CLOSED[pos_closed] = succesor[k];

            }
            

        }
        CLOSED.push_back(p);
    }
    float mini = TAB[0][0]->get_f_score();
    int i_save=0;
    int j_save = 0;
    for(int i=0; i<COLONNE; i++){
        for(int j=0; j <LIGNE;j++){
            if ((mini)< TAB[i][j]->get_f_score()){
                mini= TAB[i][j]->get_f_score();
                i_save= i;
                j_save= j;
            }
        }
    }
    
    return defilement (TAB[i_save][j_save]);// cas si case final blocké par obstacle case avec le plus petit f devient la new destination (et on a deja calculer f)
}






Vecteur Move(Vecteur start, Vecteur destination){
    vector<Vecteur> tabl_obstacle; //init avec les obsatcle recuperr a un moment
    return *(astar_(tabl_obstacle,start,destination).begin());
}







