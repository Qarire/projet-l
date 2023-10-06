#include <iostream>
using namespace std;
#include "Astar.h"

int main(){
    

    Vecteur inint = *(new Vecteur(0,0));
    Vecteur fin = *(new Vecteur(10,10));

    Astar* a = new Astar(25,25);
    cout<<"hallo";
    a->Move(inint, fin);

    
    
    return 0;
}