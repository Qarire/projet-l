#include <iostream>
#include <utility>
#include <stdlib.h>   

#include "Game.h"
#include "Field.h"
#include "Updater.h"
#include "Drawer.h"

#include "raylib.h"

#define PLAYER_SIZE      26  
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
    
    field->Init(make_pair(50, 50));
    game->Init(); drawer->Init();
    updater->Init(new Behavior( events ));

    int Height = field->getHeight();
    int Width = field->getWidth();

    float screenWidth = 1680;
    float screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "Game Window");
    Texture2D texture = LoadTexture("img/Sprite.png");                                      
    
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

   
    pair<bool, CharacterData*> verif_moov;

    Vector2 My_Mouse;
       
    int width35 = screenWidth * 0.35;
    int width25 = screenWidth * 0.1;

    int PosXPink = width35;
    int PosXGreen = PosXPink + width25;
    int PosXRed = PosXGreen + width25;
    int PosXGray = PosXRed + width25;
    int PosXBlue = PosXGray + width25;
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) { // Detect window close button or ESC key 
    
        My_Mouse = GetMousePosition();
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ) {
            
            int it = field->getCharacterDataList().size(); 
            
            if ((My_Mouse.x > PosXPink && My_Mouse.x < PosXPink + screenWidth* 0.07) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.07  )) {
                CharacterData* new_Support_perso = new CharacterData(seconde_team,stat_perso,23,44,Support,Support);
                field->addCharacterData(new_Support_perso);
                new_Support_perso->setPosition(Position(screenHeight * 0.775,100 + it * 100));
            }

            if ((My_Mouse.x > PosXGreen && My_Mouse.x < PosXGreen + screenWidth * 0.07) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.07  )) {
                CharacterData* new_archer_perso = new CharacterData(seconde_team,stat_perso,23,44,Archer,Tank);
                field->addCharacterData(new_archer_perso);
                new_archer_perso->setPosition(Position(screenHeight * 0.775,100 + it * 100));
            }

            if ((My_Mouse.x > PosXRed && My_Mouse.x < PosXRed + screenWidth * 0.07) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.07  )) {
                CharacterData* new_Tank_perso = new CharacterData(seconde_team,stat_perso,23,44,Tank,Tank);
                field->addCharacterData(new_Tank_perso);
                new_Tank_perso->setPosition(Position(screenHeight * 0.775 ,100 + it * 100));
            }

            if ((My_Mouse.x > PosXGray && My_Mouse.x < PosXGray + screenWidth * 0.07) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.07  )) {
                CharacterData* new_Sorcerer_perso = new CharacterData(seconde_team,stat_perso,23,44,Sorcerer,Melee);
                field->addCharacterData(new_Sorcerer_perso);
                new_Sorcerer_perso->setPosition(Position(screenHeight * 0.775,100 + it * 100));
            }

            if ((My_Mouse.x > PosXBlue && My_Mouse.x < PosXBlue + screenWidth * 0.07) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.07  )) {
                CharacterData* new_Melee_perso = new CharacterData(seconde_team,stat_perso,23,44,Melee,Tank);
                field->addCharacterData(new_Melee_perso);
                new_Melee_perso->setPosition(Position(screenHeight * 0.775,100 + it * 100));
            }
        }
        
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) ) {

            tabcharact = field->getCharacterDataList(); 

            
            
            for (int i=0;i<tabcharact.size(); i++) {
                
                Position pos_p = tabcharact[i]->getPosition();
                if((My_Mouse.x > pos_p.x && My_Mouse.x < pos_p.x + PLAYER_SIZE ) && (My_Mouse.y > pos_p.y && My_Mouse.y < pos_p.y + PLAYER_SIZE)) {
                    verif_moov.first = true;
                    verif_moov.second = tabcharact[i];
                  
                }  

            }
         
        }

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && verif_moov.first == true && My_Mouse.y < 750 && My_Mouse.y > 325) {

            
            verif_moov.second->setPosition(Position(My_Mouse.y - PLAYER_SIZE /2,My_Mouse.x - PLAYER_SIZE /2));
        }

        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            verif_moov.first = false;
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
                        cout << "player x : " <<playerTileX  << endl;
                        cout << "player y : " << playerTileY  << endl;

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
            }
            
      
        }
        //Le shop
     
        DrawRectangle(PosXPink, 800, screenWidth * 0.07 , screenWidth * 0.07 , PINK);
        DrawRectangle(PosXGreen, 800, screenWidth * 0.07 , screenWidth * 0.07 , GREEN);
        DrawRectangle(PosXRed, 800, screenWidth * 0.07 , screenWidth * 0.07 , RED);
        DrawRectangle(PosXGray, 800, screenWidth * 0.07 , screenWidth * 0.07 , GRAY);
        DrawRectangle(PosXBlue, 800, screenWidth * 0.07 , screenWidth * 0.07 , BLUE);
        

        //Le Banc
        
        DrawLine(0, screenHeight * 0.8333, screenWidth, 750, BLACK );
        DrawLine(0, screenHeight * 0.7222, screenWidth, 650, BLACK );
        
        //delimitation des deux camps enemis
        DrawLine(0,screenHeight * 0.3611, screenWidth, 325, RED);
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