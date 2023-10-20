#include "Astar.h"
const int MAX =100000;
const int COLONNE =25;
const int LIGNE =30;





int Astar::Heuristic(Vecteur start, Vecteur objective){
    int diffX = start.getX() - objective.getX();
    int diffY = start.getY() - objective.getY();
    return  abs(diffX) + abs(diffY);
}
    
int Astar::fscore(Case* case1){
    return case1->get_g_score() + case1->get_h_score();
}

/*bool case_valide(Vecteur case1){
        return (case1.getx()>=0)&&(case1.gety()>=0)&&(case1.getx()<colone)&&(case1.gety()<ligne);
    }*/ // on considere pour l'intsant que chaque case est accessible independamment de la position des ennemis

bool Astar::destination(Vecteur depart, Vecteur arrive){
    //cout<<"dest\n";
    return (depart.getX() == arrive.getX())&&(depart.getY() == arrive.getY());
}

bool Astar::est_dedans(int i, int TAILLE_TERRAIN){
    return (i>=0)&&(i<TAILLE_TERRAIN);
}



vector<Case*> Astar::case_autour(vector<vector<Case*>> TAB,Case* case1,Vecteur arrive,vector<Case*> CLOSED){
    vector<Case*> liste;
    cout<<"case_autour\n";
    cout <<case1->get_pos().getX();
    cout<<",";
    cout<<case1->get_pos().getY();
    cout<<"\n\n";
    int x = case1->get_pos().getX();
    int y = case1->get_pos().getY();
    for(int i=-1+x; (i<2+x); i++){ 
        for(int j=-1+y; (j<2+y);j++){
            cout<<"i,j : ";
            cout<<i,j;
            cout<<"\n";
            if((est_dedans(i,COLONNE))&&(est_dedans(j,LIGNE))&&(TAB[i][j]->get_accessible()== true)&&(!((i==x)&&(j==y)))){ // on verif que cest dans le terrain, que case accessible (et pas obstrué par ennemie...)
                //cout<<"test appartient       case_autour\n";                                                              // et que ce n'est pas le case en elle meme ou son parent
                
                int test_closed = appartient_list(TAB[i][j],CLOSED);
                //cout<< test_closed;
                //cout<<" fin test appartient       case_autour\n";
                if(test_closed<0){                                                                              
                    TAB[i][j]->set_parent(case1);
                }
                else{
                    continue;
                }
                                                                                       
                //cout<< case1->get_parent();// -> nullptr renvoit 0
                //cout<<"  addresse parent\n";
                liste.push_back(TAB[i][j]);
                TAB[i][j]->set_h_score(Heuristic(TAB[i][j]->get_pos(),arrive));
                cout<<TAB[i][j]->get_h_score();
                if((abs(i)+abs(j))==2){
                    TAB[i][j]->set_g_score(TAB[i][j]->get_parent()->get_g_score() +1.41);
                }
                else{
                    TAB[i][j]->set_g_score(TAB[i][j]->get_parent()->get_g_score() +1);
                }
                cout<<" h,g ";
                cout<<TAB[i][j]->get_g_score();
                TAB[i][j]->set_f_score(fscore(TAB[i][j]));
                cout<<"\n";
                /*cout<<i;
                cout<<",";
                cout<<j;
                cout<<"\n";*/
                cout<<"pos de la case  :  ";
                cout <<TAB[i][j]->get_pos().getX();
                cout<<",";
                cout<<TAB[i][j]->get_pos().getY();
                cout<<"\n\n";
            }
            //cout<<abs(i)*3+abs(j);
            //cout<<"\n";
        }
    }
    
    cout<<liste.size();
    cout<<" taille de liste\n";
    cout<<"case_autour_fin\n\n\n\n";
    
    return liste;
}


int Astar::min_f_score( vector<Case*> tab){
    cout<<"recherche min f  :  \n";
    float mini = tab[0]->get_f_score();
    int j=0;
    cout<<"pos de la case  :  ";
    cout<<tab[0]->get_pos().getX();
    cout<<",";
    cout<<tab[0]->get_pos().getY();
    cout<<"\n";
    cout<<"f score  :  ";
    cout<<tab[0]->get_f_score();
    cout<<"\n";
    for(int i = 1; i< tab.size();i++){
        cout<<"pos de la case  :  ";
        cout<<tab[i]->get_pos().getX();
        cout<<",";
        cout<<tab[i]->get_pos().getY();
        cout<<"\n";
        cout<<"f score  :  ";
        cout<<tab[i]->get_f_score();
        cout<<"\n";
        if ((mini)> tab[i]->get_f_score()){

            mini= tab[i]->get_f_score();
            j= i;
            //cout<<j;
        }
    }
    cout<<"pos de la case avec le min f :  ";
    cout<<tab[j]->get_pos().getX();
    cout<<",";
    cout<<tab[j]->get_pos().getY();
    cout<<"\n";
    cout<<"fin recherche min f  :  ";
    cout<<"\n";
    return j;
}

int Astar::appartient_list(Case* case1, vector<Case*> liste){
    /*cout<<"appartient_liste \n";
    cout<<"pos de la case  :  ";
    cout <<case1->get_pos().getX();
    cout<<",";
    cout<<case1->get_pos().getY();
    cout<<"\n\n";*/
    for (int i = 0 ; i<liste.size(); i++){
        if ((case1->get_pos() == liste[i]->get_pos())){

            /*cout<<"true \n";
            cout <<liste[i]->get_pos().getX();
            cout<<",";
            cout<<liste[i]->get_pos().getY();
            cout<<"\n";/*
            cout<<"vs \n";
            cout <<liste[i]->get_pos().getX();
            cout<<",";
            cout<<liste[i]->get_pos().getY();
            cout<<"\n";
            cout<<"vs \n";
            cout <<case1->get_parent();
            cout<<"\n";
            cout<<"vs \n";
            cout <<liste[i]->get_parent();
            cout<<"\n";*/

            return i;

        }
        /*else{
            cout<<"false \n";
            cout <<case1->get_pos().getX();
            cout<<",";
            cout<<case1->get_pos().getY();
            cout<<"\n";
            cout<<"vs \n";
            cout <<liste[i]->get_pos().getX();
            cout<<",";
            cout<<liste[i]->get_pos().getY();
            cout<<"\n";
            cout<<"vs \n";
            cout <<case1->get_parent();
            cout<<"\n";
            cout<<"vs \n";
            cout <<liste[i]->get_parent();
            cout<<"\n";
        }*/
    }
    //cout<<"false \n";
    return -1;
}
/*
vector<Vecteur> Astar::defilement (Case* case1){ // renvoie liste hors pas pratique car seulemrnt besoin du next move
    vector<Vecteur> liste;
    Case* p =case1;
    //cout<<p;
    cout<<"\n";
    while(p->get_parent() != nullptr){
        
        liste.push_front(p->get_pos());
        
        //cout<< p;
        cout<<liste.size();
        //cout<<"\n";
        cout<<"\n";
        cout <<p->get_pos().getX();
        cout<<",";
        cout<<p->get_pos().getY();
        cout<<"\n";
        cout<<"\n";
        p = p->get_parent();

    }
    return liste;
}*/



Vecteur Astar::defilement (Case* case1){
    //vector<Vecteur> liste;
    Case* p =case1;
    Vecteur res;
    //cout<<p;
    //cout<<"\n";
    while(p->get_parent() != nullptr){
        res = p->get_pos();
        //liste.push_back(res);
        
        //cout<< p;
        //cout<<liste.size();
        //cout<<"\n";
        cout<<"\n";
        cout <<p->get_pos().getX();
        cout<<",";
        cout<<p->get_pos().getY();
        cout<<"\n";
        cout<<"\n";
        p = p->get_parent();

    }
    return res;
}

Vecteur Astar::algo_Astar (vector<Vecteur> tabl_obstacle, Vecteur depart, Vecteur objectif){
    //cout<<"1\n";
    vector<vector<Case*>> TAB;
    //cout<<"2\n";

    for (int i =0 ; i< COLONNE ; i++){// modif apres en fonction de la tailled efield
        vector<Case*> tab;
        for (int j =0 ; j< LIGNE ; j++){
            Case* c_ = new Case(Vecteur(i,j),MAX,MAX,MAX,true,nullptr);
            //cout<<"2.1\n";
            tab.push_back(c_);
        }
        TAB.push_back(tab);
    }
    //cout<<"3\n";
    for (int i =0; i< tabl_obstacle.size(); i++){
        TAB[tabl_obstacle[i].getX()][tabl_obstacle[i].getY()] ->set_accessible(false) ;
    }
    //cout<<"4\n";
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
    
    //cout<<"5\n";
    while (!OPEN.empty()){
        int i_min_f = min_f_score(OPEN);
        Case* p = OPEN[i_min_f];
        OPEN.erase(OPEN.begin()+i_min_f);
        //cout<<"5.1\n";
        
        vector<Case*> succesor = case_autour(TAB,p,objectif,CLOSED);
        //cout<<size(succesor);
        //cout<<size(CLOSED);
        //cout<<"\n";
        for (int k=0; k< size(succesor);k++){
            //cout<<"alllll\n";
            if (destination(succesor[k]->get_pos(),objectif)){// pas testé encore
                cout<<"5.78\n";
                return defilement (succesor[k]); // bug defilement 
            }
            //cout<<"5.25\n";
            int pos_closed = appartient_list(succesor[k],CLOSED);
            int pos_open = appartient_list(succesor[k],OPEN);
            //cout<<"5.3\n";
            if(pos_closed >=0){//pas etsté
                //cout<<"5.35\n";
                continue;
            }
            //cout<<"5.4\n";
            if(pos_open <0){//pas test
                //cout<<"5.45\n";
                OPEN.push_back(succesor[k]);
            }
            if(pos_open >=0 && succesor[k]->get_g_score() < OPEN[pos_open]->get_g_score()){//pas etsté
                //cout<<"5.55\n";
                OPEN[pos_open] = succesor[k];
            }
            //cout<<"5.5\n";
            //cout<<size(OPEN);
            //cout<<size(CLOSED);
            //cout<<"\n";
        }
        CLOSED.push_back(p);

        //cout<<size(OPEN);
        //cout<<size(CLOSED);
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
    Vecteur p= algo_Astar(tabl_obstacle,start,destination);
    return p;
}







