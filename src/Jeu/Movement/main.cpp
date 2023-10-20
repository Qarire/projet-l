#include <iostream>
using namespace std;
#include "Astar.h"

int main(){
    

    Vecteur inint = *(new Vecteur(1,0));
    Vecteur fin = *(new Vecteur(0,4));

    Astar* a = new Astar(25,25);
    Vecteur x = a->Move(inint, fin);

    cout<<"next deplacement :";
    cout <<x.getX();;
    cout<<",";
    cout<<x.getY();;
    cout<<"\n\n";
    
    return 0;
}