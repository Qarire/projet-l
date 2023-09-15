#include "Terrain.h"
#include <iostream>


using namespace std;

Terrain::Terrain() {
    dimx=0;
    dimy=0;
}

Terrain::Terrain(unsigned int x, unsigned int y) {
    dimx = x;
    dimy = y;
}

Terrain::~Terrain(){

}

unsigned int Terrain::getDimx() const {
    return dimx;
}

unsigned int Terrain::getDimy() const {
    return dimy;
}

void Terrain::setDimx(unsigned int dimx1) {
    dimx=dimx1;
}

void Terrain::setDimy(unsigned int dimy1) {
    dimy=dimy1;
}