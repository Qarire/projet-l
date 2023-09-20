#include <iostream>

#include "Jeu/Jeu.h"
#include "Display/Displayer.h"

using namespace std;

int main() {
    Jeu* jeu = new Jeu();
    Displayer* displayer = new Displayer(jeu->getTerrain());

    do {
        jeu->Update(0);
        displayer->Display();
    }while(true);


    delete jeu;
}