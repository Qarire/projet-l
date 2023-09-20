#include "Vecteur.h"


using namespace std;

Vecteur::Vecteur() {
    x = 0;
    y = 0;
}
Vecteur::Vecteur(float a, float b) {
    x = a;
    y = b;
}
Vecteur::~Vecteur(){

}
float Vecteur::getX() const{
    return x;
}
float Vecteur::getY() const{
    return y;
}
void Vecteur::setX(float x1){
    x=x1;
}
void Vecteur::setY(float y1){
    y=y1;
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