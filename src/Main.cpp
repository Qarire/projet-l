#include <iostream>
#include <utility>

#include "Game.h"
#include "Field.h"
#include "Updater.h"
#include "Drawer.h"
#include "ConsequenceTestDelete.h"
#include "ConditionTrue.h"

using namespace std;


// compilation :
// windows: cp src/*.cpp, src/mvc/controller/*.cpp, src/mvc/model/*.cpp, src/mvc/operators/*.cpp, src/mvc/controller/Attack/*.cpp, src/mvc/controller/Movement/*.cpp, src/mvc/controller/Events/*.cpp, src/mvc/controller/Events/Behavior/*.cpp, src/mvc/controller/Events/Condition/*.cpp, src/mvc/controller/Events/Consequence/*.cpp, src/mvc/model/data/*.cpp,src/mvc/controller/*.h, src/mvc/model/*.h, src/mvc/operators/*.h, src/mvc/controller/Attack/*.h, src/mvc/controller/Movement/*.h, src/mvc/controller/Events/*.h, src/mvc/controller/Events/Behavior/*.h, src/mvc/controller/Events/Condition/*.h, src/mvc/controller/Events/Consequence/*.h, src/mvc/model/data/*.h build/fileMesh/ && g++ build/fileMesh/*.cpp -o build/prog.exe && build/prog.exe
// linux : cp src/*.cpp src/mvc/controller/*.cpp src/mvc/model/*.cpp src/mvc/operators/*.cpp src/mvc/controller/Attack/*.cpp src/mvc/controller/Movement/*.cpp src/mvc/controller/Events/*.cpp src/mvc/controller/Events/Behavior/*.cpp src/mvc/controller/Events/Condition/*.cpp src/mvc/controller/Events/Consequence/*.cpp src/mvc/model/data/*.cpp src/mvc/controller/*.h src/mvc/model/*.h src/mvc/operators/*.h src/mvc/controller/Attack/*.h src/mvc/controller/Movement/*.h src/mvc/controller/Events/*.h src/mvc/controller/Events/Behavior/*.h src/mvc/controller/Events/Condition/*.h src/mvc/controller/Events/Consequence/*.h src/mvc/model/data/*.h build/fileMesh/ && g++ build/fileMesh/*.cpp -o build/prog.exe && build/prog.exe

int main() {
// Initialization
    Field* field = Field::GetInstance();
    Game* game = Game::GetInstance();
    Updater* updater = Updater::GetInstance();
    Drawer* drawer = Drawer::GetInstance();

    vector<Event*> events = {new Event(new ConditionTrue(), new ConsequenceTestDelete())};

    field->Init(make_pair(50, 50));
    game->Init(); drawer->Init();
    updater->Init(new Behavior( events ));

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
