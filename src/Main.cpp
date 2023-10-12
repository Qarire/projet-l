#include <iostream>
#include <utility>
#include <stdlib.h>   

#include "Game.h"
#include "Field.h"
#include "Updater.h"
#include "Drawer.h"
#include "raylib.h"

#define PLAYER_SIZE      16  

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

     field->Init(make_pair(1200, 800));
     game->Init(); updater->Init(); drawer->Init();


    int Height = field->getHeight();
    int Width = field->getWidth();
    InitWindow(Height, Width, "Game Window");


//CharacterData(Team team, Stats stats, float healModifier, float damageModifier, Type type, Type favoriteEnemyType);
   
    ValueMaxed value;
    value.Max = 100;
    value.Value = 30;
    Stats stat_perso;
    stat_perso.hp = value;
    stat_perso.def = value;
    stat_perso.atk = value;
    Team first_team = RED1;
    Position pos = Position(Width/2,Height/2);
    CharacterData* first_perso = new CharacterData(first_team,stat_perso,23,44,Melee,Tank);
    first_perso->setPosition(pos);
    
    field->addCharacterData(first_perso);

    vector<CharacterData*> tabcharact = field->getCharacterDataList();

    Position playerPosition = tabcharact[0]->getPosition();
    int playerTileX = playerPosition.x;
    int playerTileY = playerPosition.y;

    RenderTexture2D fogOfWar = LoadRenderTexture(Height - 10, Width - 10);
    SetTextureFilter(fogOfWar.texture, TEXTURE_FILTER_BILINEAR);
    SetTargetFPS(60); 

    while (!WindowShouldClose()) { // Detect window close button or ESC key 
        
        BeginTextureMode(fogOfWar);
        EndTextureMode();


        BeginDrawing();
        //DrawRectangleV(playerPosition, (Vector2){ PLAYER_SIZE, PLAYER_SIZE }, RED);
        DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, RED);
        DrawText(TextFormat("Current tile: [%i,%i]", playerTileX, playerTileY), 10, 10, 20, RAYWHITE);
        EndDrawing();

        
    }   

    UnloadRenderTexture(fogOfWar);  // Unload render texture

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;



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