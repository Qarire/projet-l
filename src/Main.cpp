#include <iostream>

#include "Jeu/Jeu.h"
#include "Display/Displayer.h"

using namespace std;

int main() {
    Jeu* jeu = Jeu::getInstance();
    Displayer* displayer = Displayer::getInstance();

    do {
        jeu->Update(0);
        displayer->Display();
    }while(true);


    delete jeu;
}