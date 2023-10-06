#include "Astar.h"
const int MAX =100000;
const int COLONNE =25;
const int LIGNE =28;





int Astar::Heuristic(Vecteur start, Vecteur objective){
    int diffX = objective.getX() - start.getX();
    int diffY = objective.getY() - start.getY();
    return diffY + diffY;
}
    
int Astar::fscore(Case case1){
    return case1.get_g_score() + case1.get_h_score();
}

/*bool case_valide(Vecteur case1){
        return (case1.getx()>=0)&&(case1.gety()>=0)&&(case1.getx()<colone)&&(case1.gety()<ligne);
    }*/ // on considere pour l'intsant que chaque case est accessible independamment de la position des ennemis

bool Astar::destination(Vecteur depart, Vecteur arrive){
    cout<<"dest\n";
    return (depart.getX() == arrive.getX())&&(depart.getY() == arrive.getY());
}

vector<Case*> Astar::case_autour(vector<vector<Case*>> TAB,Case case1,Vecteur arrive){
    vector<Case*> liste;
    cout<<"case_autour\n";
    int x = case1. get_pos(). getX();
    int y = case1.get_pos(). getY();
    for(int i=-1+x; (i<2+x)&&(i>=0)&&(i<= COLONNE); i++){ //RECUPERER LES TAILLE DU TERRAIN
        for(int j=-1+y; (j<2+x)&&(j>=0)&&(j<= LIGNE);j++){
            cout<<"fda";
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
            cout<<"%d\n",abs(i)*3+abs(j);
        }
    }

    cout<<liste.size();
    cout<<"case_autour_fin\n";
    
    return liste;
}


int Astar::min_f_score( vector<Case*> tab){
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

bool Astar::appartient_list(Case* case1, vector<Case*> liste){
    for (int i = 0 ; i<liste.size(); i++){
        if (case1== liste[i] ){
            return i;
        }
    }
    return -1;
}

vector<Vecteur> Astar::defilement (Case* case1){
    vector<Vecteur> liste;
    Case* p =case1;
    while(p != nullptr){
        liste.push_back(case1->get_pos());
        p = case1->get_parent();
        cout <<"%d, %d", case1->get_pos().getX(),case1->get_pos().getY();


    }
    return liste;
}

vector<Vecteur> Astar::algo_Astar (vector<Vecteur> tabl_obstacle, Vecteur depart, Vecteur objectif){
    cout<<"1\n";
    vector<vector<Case*>> TAB;
    cout<<"2\n";

    for (int i =0 ; i< COLONNE ; i++){// modif apres en fonction de la tailled efield
        vector<Case*> tab;
        for (int j =0 ; j< LIGNE ; j++){
            Case* c_ = new Case(Vecteur(i,j),MAX,MAX,MAX,true,nullptr);
            cout<<"2.1\n";

            tab.push_back(c_);
        }
        TAB.push_back(tab);
    }
    cout<<"3\n";
    for (int i =0; i< tabl_obstacle.size(); i++){
        TAB[tabl_obstacle[i].getX()][tabl_obstacle[i].getY()] ->set_accessible(true) ;
    }
    cout<<"4\n";
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
    
    cout<<"5\n";
    while (!OPEN.empty()){
        int i_min_f = min_f_score(OPEN);
        Case* p = OPEN[i_min_f];
        OPEN.erase(OPEN.begin()+i_min_f);
        cout<<"5.1\n";
        
        vector<Case*> succesor = case_autour(TAB,*p,objectif);
        for (int k=0; k< 8;k++){
            cout<<"alllll\n";
            if (destination(succesor[k]->get_pos(),objectif)){
                cout<<"5.78\n";
                return defilement (succesor[k]);
            }
            cout<<"5.25\n";
            int pos_closed = appartient_list(succesor[k],CLOSED);
            int pos_open = appartient_list(succesor[k],OPEN);
            cout<<"5.3\n";
            if(pos_open >=0 && succesor[k]->get_f_score() < OPEN[pos_open]->get_f_score()){
                OPEN[pos_open] = succesor[k];
            }
            cout<<"5.4\n";
            if(pos_closed >=0 && succesor[k]->get_f_score() < CLOSED[pos_open]->get_f_score()){
                OPEN.push_back(CLOSED[pos_closed]);
                CLOSED[pos_closed] = succesor[k];

            }
            cout<<"5.5\n";

        }
        CLOSED.push_back(p);
    }
    cout<<"6\n";
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
    cout<<"7\n";
    return defilement (TAB[i_save][j_save]);// cas si case final blocké par obstacle case avec le plus petit f devient la new destination (et on a deja calculer f)
}







Vecteur Astar::Move(Vecteur start, Vecteur destination){
    vector<Vecteur> tabl_obstacle; //init avec les obsatcle recuperr a un moment
    //cout<<"hallo";
    return *(algo_Astar(tabl_obstacle,start,destination).begin());
}







