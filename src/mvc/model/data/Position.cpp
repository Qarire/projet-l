#include "Position.h"
using namespace std;


Position::Position() {
    y = 200;
    x = 100;
}
Position::Position(float y, float x) {
    this->y = y;
    this->x = x;
}
Position::~Position(){};


float Position::distance(Position posA, Position posB) {
    return sqrt(
        pow(posB.x - posA.x, 2) + pow(posB.y - posA.y, 2)
    );
}


Vector2 Position::toVector2() {
    return Vector2{x, y};
}


bool Position::operator==(Position p) {
    return (x==p.x && y==p.y);
}
Position Position::operator+(Position p) {
    Position res;
    res.x = x + p.x;
    res.y = y + p.y;
    return res;
}
Position Position::operator+(float a) {
    Position res;
    res.x = x + a;
    res.y = y + a;
    return res;
}

Position Position::operator-(Position p) {
    Position res;
    res.x = x - p.x;
    res.y = y - p.y;
    return res;
}

Position Position::operator-(float a) {
    Position res;
    res.x = x - a;
    res.y = y - a;
    return res;

}
ostream& operator<<(ostream& os, const Position& position) {
        os << "[ "<< position.y << ", " << position.x << " ]";
        return os;
}
