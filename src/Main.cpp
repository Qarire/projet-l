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

    field->Init(make_pair(1680, 1050));
    game->Init(); drawer->Init();
    updater->Init(new Behavior( events ));


    int Height = field->getHeight();
    int Width = field->getWidth();
    InitWindow(Height, Width, "Game Window");


//CharacterData(Team team, Stats stats, float healModifier, float damageModifier, Type type, Type favoriteEnemyType);
   
    ValueMaxed value;
     vector<CharacterData*> tabcharact;
    int playerTileX; 
    int playerTileY; 

    value.Max = 100;
    value.Value = 30;
    Stats stat_perso;
    stat_perso.hp = value;
    stat_perso.def = value;
    stat_perso.atk = value;
    Team first_team = RED1;
    Team seconde_team = Blue;

    Position pos = Position(200,100);

    CharacterData* new_r_perso = new CharacterData(first_team,stat_perso,23,44,Tank,Tank);
    new_r_perso->setPosition(pos);
    CharacterData* new_b_perso = new CharacterData(seconde_team,stat_perso,23,44,Melee,Melee);
    new_b_perso->setPosition(pos);

   
   
    
    /// partie fond map
    Color *pixels = (Color *)malloc(Width*Height*sizeof(Color));

    for (int y = 0; y < Height; y++)
    {
        for (int x = 0; x < Width; x++)
        {
            if (((x/32+y/32)/1)%2 == 0) 
                pixels[y*Width + x] = DARKGREEN;
            else 
                pixels[y*Width + x] = GREEN;
        }
    }

        Image checkedIm = {
        .data = pixels,             // We can assign pixels directly to data
        .width = Width,
        .height = Height,
        .mipmaps = 1,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
        
    };

    Texture2D checked = LoadTextureFromImage(checkedIm);
    UnloadImage(checkedIm); 

    /////

    //RenderTexture2D fogOfWar = LoadRenderTexture(Height - 10, Width - 10);
    //SetTextureFilter(fogOfWar.texture, TEXTURE_FILTER_BILINEAR);
    SetTargetFPS(60); 

    while (!WindowShouldClose()) { // Detect window close button or ESC key 
        
        //BeginTextureMode(fogOfWar);
        //EndTextureMode();


        if(IsKeyPressed(KEY_R)) {
            field->addCharacterData(new_r_perso);
            tabcharact = field->getCharacterDataList();  
        }

        if(IsKeyPressed(KEY_B)) {
            field->addCharacterData(new_b_perso);
            tabcharact = field->getCharacterDataList();     
        }

        BeginDrawing();
        
        ClearBackground(RAYWHITE);

        DrawTexture(checked, Width/2 - checked.width/2, Height/2 - checked.height/2, Fade(WHITE, 0.5f));


        for(int i=0;i<tabcharact.size();i++)
        {
            Position playerPosition = tabcharact[i]->getPosition();
            Team equipe = tabcharact[i]->getTeam();
            if(equipe == RED1) {
                
                playerTileX = playerPosition.x + i*100;
                playerTileY = playerPosition.y;

                DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, RED);
            }else
            {
                playerTileX = playerPosition.x + i*100;
                playerTileY = Width - playerPosition.y ;

                DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, BLUE);
            }
            
           
            
           // DrawText(TextFormat("Current tile: [%i,%i]", playerTileX, playerTileY), 10, 10, 20, RAYWHITE);
        }
        
        EndDrawing(); 
    }   

   
    UnloadTexture(checked); 
    CloseWindow();         
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