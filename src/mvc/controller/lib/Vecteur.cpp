#include "Position.h"

using namespace std;


Position::Position() {
    y = 0;
    x = 0;
}
Position::Position(float y, float x) {
    this->y = y;
    this->x = x;
}
Position::~Position(){}

float Position::x const{
    return x;
}
float Position::y const{
    return y;
}
void Position::setX(float x){
    this->x=x;
}
void Position::setY(float y){
    this->y=y;
}
bool Position::operator==(Position v){
    return (x==v.x && y==v.y);
}
Position Position::operator+(Position v){
    Position res;
    res.x = x + v.x;
    res.y = y + v.y;
    return res;
}

Position Position::operator-(Position v){
    Position res;
    res.x = x - v.x;
    res.y = y - v.y;
    return res;
}
Position Position::operator+(float a){
    Position res;
    res.x = x + a;
    res.y = y + a;
    return res;
}
Position Position::operator-(float a){
    Position res;
    res.x = x - a;
    res.y = y - a;
    return res;
}


ostream& operator<<(ostream& os, const Position& Position) {
    os << "[ "<< Position.y << ", " << Position.x << " ]";
    return os;
}