#include "Vecteur.h"

using namespace std;


Vecteur::Vecteur() {
    y = 0;
    x = 0;
}
Vecteur::Vecteur(float y, float x) {
    this->y = y;
    this->x = x;
}
Vecteur::~Vecteur(){}

float Vecteur::getX() const{
    return x;
}
float Vecteur::getY() const{
    return y;
}
void Vecteur::setX(float x){
    this->x=x;
}
void Vecteur::setY(float y){
    this->y=y;
}
bool Vecteur::operator==(Vecteur v){
    return (x==v.x && y==v.y);
}
Vecteur Vecteur::operator+(Vecteur v){
    Vecteur res;
    res.x = x + v.getX();
    res.y = y + v.getY();
    return res;
}

Vecteur Vecteur::operator-(Vecteur v){
    Vecteur res;
    res.x = x - v.getX();
    res.y = y - v.getY();
    return res;
}
Vecteur Vecteur::operator+(float a){
    Vecteur res;
    res.x = x + a;
    res.y = y + a;
    return res;
}
Vecteur Vecteur::operator-(float a){
    Vecteur res;
    res.x = x - a;
    res.y = y - a;
    return res;
}