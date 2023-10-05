#include <iostream>
#include <utility>

#include "Game.h"
#include "Field.h"
#include "Updater.h"
#include "Drawer.h"

using namespace std;


// compilation :
// windows: cp src/*.cpp, src/mvc/controller/*.cpp, src/mvc/model/*.cpp, src/mvc/operators/*.cpp, src/mvc/controller/Attack/*.cpp, src/mvc/controller/Movement/*.cpp, src/mvc/model/data/*.cpp,src/mvc/controller/*.h, src/mvc/model/*.h, src/mvc/operators/*.h, src/mvc/controller/Attack/*.h, src/mvc/controller/Movement/*.h, src/mvc/model/data/*.h build/fileMesh/ && g++ build/fileMesh/*.cpp -o build/prog.exe && build/prog.exe
// linux: cp src/*.cpp src/mvc/controller/*.cpp src/mvc/model/*.cpp src/mvc/operators/*.cpp src/mvc/controller/Attack/*.cpp src/mvc/controller/Movement/*.cpp src/mvc/model/data/*.cpp src/mvc/controller/*.h src/mvc/model/*.h src/mvc/operators/*.h src/mvc/controller/Attack/*.h src/mvc/controller/Movement/*.h src/mvc/model/data/*.h build/fileMesh/ && g++ build/fileMesh/*.cpp -o build/prog.exe && build/prog.exe


int main() {
// Initialization
    Field* field = Field::GetInstance();
    Game* game = Game::GetInstance();
     Updater* updater = Updater::GetInstance();
     Drawer* drawer = Drawer::GetInstance();

     field->Init(make_pair(50, 50));
     game->Init(); updater->Init(); drawer->Init();

// Game loop
    // while(true) {
    //     updater->Update(1);
    // }

// Endings
    delete field;
    delete game;
    delete updater;
    delete drawer;
}
