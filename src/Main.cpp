#include <iostream>
#include <utility>
#include <stdlib.h>   

#include "Game.h"
#include "Field.h"
#include "Updater.h"
#include "Drawer.h"
#include "raylib.h"

#define PLAYER_SIZE      16  
#include "ConsequenceTestDelete.h"
#include "ConditionTrue.h"

using namespace std;


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