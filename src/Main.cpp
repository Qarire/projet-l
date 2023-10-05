#include <iostream>
#include <utility>

#include "Game.h"
#include "Field.h"
#include "Updater.h"
#include "Drawer.h"

using namespace std;


// compilation :
// windows : cp src/*.cpp, src/lib/*.cpp, src/Display/*.cpp, src/Jeu/*.cpp, src/Jeu/Movement/*.cpp, src/Jeu/Personnage/*.cpp, src/Jeu/personnage/Attacks/*.cpp, src/*.h, src/lib/*.h, src/Display/*.h, src/Jeu/*.h, src/Jeu/Movement/*.h, src/Jeu/Personnage/*.h, src/Jeu/Personnage/Attacks/*.h build/fileMesh/; g++ build/fileMesh/*.cpp -o build/prog.exe && build/prog.exe
// linux cp src/*.cpp src/lib/*.cpp src/Display/*.cpp src/Jeu/*.cpp src/Jeu/Movement/*.cpp src/Jeu/Personnage/*.cpp src/Jeu/Personnage/Attacks/*.cpp src/*.h src/lib/*.h src/Display/*.h src/Jeu/*.h src/Jeu/Movement/*.h src/Jeu/Personnage/*.h src/Jeu/Personnage/Attacks/*.h build/fileMesh/; g++ build/fileMesh/*.cpp -o build/prog.exe && build/prog.exe


int main() {
// Initialization
    Field* field = Field::GetInstance();
    Game* game = Game::GetInstance();
     Updater* updater = Updater::GetInstance();
     Drawer* drawer = Drawer::GetInstance();

     field->Init(make_pair(50, 50));
     game->Init(); updater->Init(); drawer->Init();

// // Game loop
//     // while(true) {
//     //     updater->Update(1);
//     // }

// // Endings
//     delete field;
//     delete game;
//     delete updater;
//     delete drawer;
}
