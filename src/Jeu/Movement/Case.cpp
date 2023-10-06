#include "Case.h"
Case::Case() {
    pos = Vecteur(0,0);
    f_score= 0;
    h_score= 0;
    g_score= 0;
    accessible= true;
    parent= nullptr;
}
Case::Case(Vecteur v, float f, float h, float g,bool b, Case* p) {
    pos = v;
    f_score= f;
    h_score= h;
    g_score= g;
    accessible= b;
    parent= p;
}
Case::~Case(){}
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
