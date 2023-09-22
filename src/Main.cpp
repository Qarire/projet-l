#include <iostream>

#include "Jeu.h"
#include "Displayer.h"

using namespace std;


// compilation :
// windows : cp src/*.cpp, src/lib/*.cpp, src/Display/*.cpp, src/Jeu/*.cpp, src/Jeu/Movement/*.cpp, src/Jeu/Personnage/*.cpp, src/Jeu/personnage/Attacks/*.cpp, src/*.h, src/lib/*.h, src/Display/*.h, src/Jeu/*.h, src/Jeu/Movement/*.h, src/Jeu/Personnage/*.h, src/Jeu/Personnage/Attacks/*.h build/fileMesh/; g++ build/fileMesh/*.cpp -o build/prog.exe && build/prog.exe
// linux

int main() {
    Jeu* jeu = Jeu::getInstance();
    Displayer* displayer = Displayer::getInstance();

    do {
        jeu->Update(0);
        displayer->Display();
    }while(true);


    delete jeu;
}