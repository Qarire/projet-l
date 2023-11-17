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
#include "ButtonCondition.h"
#include "ConsequenceInvoke.h"

using namespace std;
/*
void MovePerso(CharacterData* perso, float x, float y)
{
    
    perso->getPosition().x = x; 
    perso->getPosition().y = y;

    
}
*/
int main2() {
// Initialization

    Field* field = Field::GetInstance();
    Game* game = Game::GetInstance();
     Updater* updater = Updater::GetInstance();
     Drawer* drawer = Drawer::GetInstance();
    
    

    int Height = field->getHeight();
    int Width = field->getWidth();

    int screenWidth = 1680;
    int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "Game Window");
    Texture2D texture = LoadTexture("img/Sprite.png");

// Init EventConditions
    /*
    Rectangle healerButtonRect = Rectangle{float(GetScreenHeight() * 0.8), float(GetScreenWidth() * 0.28), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};
    Rectangle archerButtonRect = Rectangle{float(GetScreenHeight() * 0.8), float(healerButtonRect.x + GetScreenWidth()*0.05), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};
    Rectangle tankButtonRect = Rectangle{float(GetScreenHeight() * 0.8), float(archerButtonRect.x + GetScreenWidth()*0.05), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};
    Rectangle sorcererButtonRect = Rectangle{float(GetScreenHeight() * 0.8), float(tankButtonRect.x + GetScreenWidth()*0.05), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};
    Rectangle meleeButtonRect = Rectangle{float(GetScreenHeight() * 0.8), float(meleeButtonRect.x + GetScreenWidth()*0.05), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};

    vector<EventCondition*> EventConditions = {

        new EventCondition(new ConditionTrue(), new ConsequenceTestDelete()),
        new EventCondition(new ButtonCondition(healerButtonRect), new ConsequenceInvoque(Support)),
        new EventCondition(new ButtonCondition(archerButtonRect), new ConsequenceInvoque(Archer)),
        new EventCondition(new ButtonCondition(tankButtonRect), new ConsequenceInvoque(Tank)),
        new EventCondition(new ButtonCondition(sorcererButtonRect), new ConsequenceInvoque(Sorcerer)),
        new EventCondition(new ButtonCondition(meleeButtonRect), new ConsequenceInvoque(Melee))
    };  
       
    */

    vector<EventCondition*> EventConditions = {new EventCondition(new ConditionTrue(), new ConsequenceTestDelete())};

    field->Init(make_pair(1680, 900));
    game->Init(); drawer->Init();
    updater->Init(new Behavior( EventConditions ));                                 

    vector<CharacterData*> tabcharact;
    int playerTileX; 
    int playerTileY; 

    
    pair<bool, CharacterData*> verif_moov;

    Vector2 My_Mouse;
       
    int width35 = Width * 0.35;
    int width25 = Width * 0.25;

    int PosXPink = width35;
    int PosXGreen = PosXPink + width25;
    int PosXRed = PosXGreen + width25;
    int PosXGray = PosXRed + width25;
    int PosXBlue = PosXGray + width25;
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) { // Detect window close button or ESC key 
    
        My_Mouse = GetMousePosition();
        // cout << My_Mouse.x << " " << My_Mouse.y << endl;
        
               
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) ) {

            tabcharact = field->getCharacterDataList(); 

            
            
            for (int i=0;i<tabcharact.size(); i++) {
                
                Position pos_p = tabcharact[i]->getPosition();
                if((My_Mouse.x > pos_p.x && My_Mouse.x < pos_p.x + PLAYER_SIZE ) && (My_Mouse.y > pos_p.y && My_Mouse.y < pos_p.y + PLAYER_SIZE)) {
                    verif_moov.first = true;
                    verif_moov.second = tabcharact[i];
                    //tabcharact[i]->setPosition(Position(My_Mouse.y - PLAYER_SIZE /2,My_Mouse.x - PLAYER_SIZE /2));
                  
                }  

            }
         
        }

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && verif_moov.first == true && My_Mouse.y < 750 && My_Mouse.y > 325) {

            
            verif_moov.second->setPosition(Position(My_Mouse.y - PLAYER_SIZE /2,My_Mouse.x - PLAYER_SIZE /2));
        }

        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            verif_moov.first = false;
        }

        if(field->getCharacterDataList().size() > 0) {
            // cout << field->getCharacterDataList()[0]->getPosition().x << " - " << field->getCharacterDataList()[0]->getPosition().y << endl;
        }
       

        BeginDrawing();
        
        ClearBackground(RAYWHITE);
 
        

        for(int i=0;i<tabcharact.size();i++) {
            Position playerPosition = tabcharact[i]->getPosition();
            Team equipe = tabcharact[i]->getTeam();
            Type le_type = tabcharact[i]->getType();
            if(equipe == Blue) {
            
                playerTileX = playerPosition.x;
                playerTileY = playerPosition.y;
                
                switch (le_type) {
                    case Support:
                        DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, PINK);
                        break;
                    case Tank:
                        DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, RED);
                        break;
                    case Melee:
                        DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, BLUE);
                        break;
                    case Sorcerer:
                        DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, GRAY);
                        break;
                    case Archer:
                        DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, GREEN);
                        break;
                    default:
                        DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, BLACK);
                }
            }else { 
                playerTileX = playerPosition.x + i*100;
                playerTileY = playerPosition.y;
                DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, YELLOW);
            }
            
      
        }
        //Le shop

        DrawRectangle(PosXPink, 800, Width * 0.15 , Width * 0.15 , PINK);
        DrawRectangle(PosXGreen, 800, Width * 0.15 , Width * 0.15 , GREEN);
        DrawRectangle(PosXRed, 800, Width * 0.15 , Width * 0.15 , RED);
        DrawRectangle(PosXGray, 800, Width * 0.15 , Width * 0.15 , GRAY);
        DrawRectangle(PosXBlue, 800, Width * 0.15 , Width * 0.15 , BLUE);
        
        DrawRectangle(10, 10, 10, 10, PINK);
        //void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);
        //Le Banc
        DrawLine(0, 750, Width, 750, BLACK );
        DrawLine(0, 650, Width, 650, BLACK );
        
        //delimitation des deux camps enemis
        DrawLine(0,325, Width, 325, RED);
        EndDrawing(); 
    }   

    UnloadTexture(texture); 
    //UnloadImage(perso_image); 
    CloseWindow();         
    //--------------------------------------------------------------------------------------



    return 0;



// // Endings
//     delete field;
//     delete game;
//     delete updater;
//     delete drawer;
}