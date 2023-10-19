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
/*
void MovePerso(CharacterData* perso, float x, float y)
{
    
    perso->getPosition().x = x; 
    perso->getPosition().y = y;

    
}
*/
int main() {
// Initialization
    
    Field* field = Field::GetInstance();
    Game* game = Game::GetInstance();
     Updater* updater = Updater::GetInstance();
     Drawer* drawer = Drawer::GetInstance();

    vector<Event*> events = {new Event(new ConditionTrue(), new ConsequenceTestDelete())};
    
    int screenWidth = 1680;
    int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "Game Window");
    Texture2D texture = LoadTexture("img/Sprite.png");                                      
    
    field->Init(make_pair(1680, 900));
    game->Init(); drawer->Init();
    updater->Init(new Behavior( events ));


    int Height = field->getHeight();
    int Width = field->getWidth();

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

    Position pos = Position();

    CharacterData* new_r_perso = new CharacterData(first_team,stat_perso,23,44,Tank,Tank);
    //new_r_perso->setPosition(pos);
   
    
    
    
    
    

    Vector2 My_Mouse;
       
    int width35 = Width * 0.35;
    int width25 = Width * 0.25;

    /*int PosXPink = width35;
    int PosXGreen = width35 + width25;
    int PosXRed = (width35 + width25) + width25;
    int PosXGray = ((width35 + width25) + width25) + width25;
    int PosXBlue = (((width35 + width25) + width25) + width25) + width25;*/

    int PosXPink = width35;
    int PosXGreen = PosXPink + width25;
    int PosXRed = PosXGreen + width25;
    int PosXGray = PosXRed + width25;
    int PosXBlue = PosXGray + width25;
    
    SetTargetFPS(60); 

    while (!WindowShouldClose()) { // Detect window close button or ESC key 
    
        My_Mouse = GetMousePosition();
        
        if(IsKeyPressed(KEY_R)) { //inutile mtn c'était pour test
            field->addCharacterData(new_r_perso);
            tabcharact = field->getCharacterDataList();  
        }
        
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ) {
            
            if ((My_Mouse.x > PosXPink && My_Mouse.x < PosXPink + Width * 0.15) && (My_Mouse.y > 800  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_Support_perso = new CharacterData(seconde_team,stat_perso,23,44,Support,Support);
                field->addCharacterData(new_Support_perso);
                tabcharact = field->getCharacterDataList(); 
            }

            if ((My_Mouse.x > PosXGreen && My_Mouse.x < PosXGreen + Width * 0.15) && (My_Mouse.y > 800  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_archer_perso = new CharacterData(seconde_team,stat_perso,23,44,Archer,Tank);
                field->addCharacterData(new_archer_perso);
                tabcharact = field->getCharacterDataList(); 
            }

            if ((My_Mouse.x > PosXRed && My_Mouse.x < PosXRed + Width * 0.15) && (My_Mouse.y > 800  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_Tank_perso = new CharacterData(seconde_team,stat_perso,23,44,Tank,Tank);
                field->addCharacterData(new_Tank_perso);
                tabcharact = field->getCharacterDataList(); 
            }

            if ((My_Mouse.x > PosXGray && My_Mouse.x < PosXGray + Width * 0.15) && (My_Mouse.y > 800  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_Sorcerer_perso = new CharacterData(seconde_team,stat_perso,23,44,Sorcerer,Melee);
                field->addCharacterData(new_Sorcerer_perso);
                tabcharact = field->getCharacterDataList(); 
            }

            if ((My_Mouse.x > PosXBlue && My_Mouse.x < PosXBlue + Width * 0.15) && (My_Mouse.y > 800  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_Melee_perso = new CharacterData(seconde_team,stat_perso,23,44,Melee,Tank);
                field->addCharacterData(new_Melee_perso);
                tabcharact = field->getCharacterDataList(); 
            }
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {

            for (int i=0;i<tabcharact.size(); i++) {
                
                Position pos_p = tabcharact[i]->getPosition();
                if((My_Mouse.x > pos_p.x && My_Mouse.x < pos_p.x + PLAYER_SIZE ) && (My_Mouse.y > pos_p.y && My_Mouse.y < pos_p.y + PLAYER_SIZE)) {
                    
                    tabcharact[i]->setPosition(Position(My_Mouse.x,My_Mouse.y));
                   //void DrawText(const char *text, int posX, int posY, int fontSize, Color color);
                  
                }              
            }
         
        }
       

        BeginDrawing();
        
        ClearBackground(RAYWHITE);
 
        

        for(int i=0;i<tabcharact.size();i++) {
            Position playerPosition = tabcharact[i]->getPosition();
            Team equipe = tabcharact[i]->getTeam();
            Type le_type = tabcharact[i]->getType();
            if(equipe == Blue) {
            
                playerTileX = playerPosition.x + i*100;
                playerTileY = Width - playerPosition.y ;
                
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
        
        //void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);
        //Le Banc
        DrawLine(0, 750, screenWidth, 750, BLACK );
        DrawLine(0, 650, screenWidth, 650, BLACK );
        
        //delimitation des deux camps enemis
        DrawLine(0,325, screenWidth, 325, RED);
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