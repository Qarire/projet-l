#include <iostream>

#include "Jeu/Jeu.h"

using namespace std;

int main() {
    Jeu* jeu = new Jeu();

    do {
        jeu->Update(0);
    }while(true);


    delete jeu;
}