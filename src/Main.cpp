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
    
    int screenWidth = 1380;
    int screenHeight = 800;
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
   
    
    
    pair<bool, CharacterData*> verif_moov;
   


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
        cout << verif_moov.first << endl;
    
        My_Mouse = GetMousePosition();
        // cout << My_Mouse.x << " " << My_Mouse.y << endl;
        
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ) {
            
            int it = field->getCharacterDataList().size(); 
            
            if ((My_Mouse.x > PosXPink && My_Mouse.x < PosXPink + Width * 0.15) && (My_Mouse.y > 600  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_Support_perso = new CharacterData(seconde_team,stat_perso,23,44,Support,Support);
                field->addCharacterData(new_Support_perso);
                new_Support_perso->setPosition(Position(Width -200,100 + it * 100));
                //tabcharact = field->getCharacterDataList(); 
            }

            if ((My_Mouse.x > PosXGreen && My_Mouse.x < PosXGreen + Width * 0.15) && (My_Mouse.y > 600  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_archer_perso = new CharacterData(seconde_team,stat_perso,23,44,Archer,Tank);
                field->addCharacterData(new_archer_perso);
                new_archer_perso->setPosition(Position(Width -200,100 + it * 100));
                //tabcharact = field->getCharacterDataList(); 
            }

            if ((My_Mouse.x > PosXRed && My_Mouse.x < PosXRed + Width * 0.15) && (My_Mouse.y > 600  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_Tank_perso = new CharacterData(seconde_team,stat_perso,23,44,Tank,Tank);
                field->addCharacterData(new_Tank_perso);
                new_Tank_perso->setPosition(Position(Width -200,100 + it * 100));
                //tabcharact = field->getCharacterDataList(); 
            }

            if ((My_Mouse.x > PosXGray && My_Mouse.x < PosXGray + Width * 0.15) && (My_Mouse.y > 600  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_Sorcerer_perso = new CharacterData(seconde_team,stat_perso,23,44,Sorcerer,Melee);
                field->addCharacterData(new_Sorcerer_perso);
                new_Sorcerer_perso->setPosition(Position(Width -200,100 + it * 100));
                //tabcharact = field->getCharacterDataList(); 
            }

            if ((My_Mouse.x > PosXBlue && My_Mouse.x < PosXBlue + Width * 0.15) && (My_Mouse.y > 600  && My_Mouse.y < 800 + Width * 0.15  )) {
                CharacterData* new_Melee_perso = new CharacterData(seconde_team,stat_perso,23,44,Melee,Tank);
                field->addCharacterData(new_Melee_perso);
                new_Melee_perso->setPosition(Position(Width -200,100 + it * 100));
                //tabcharact = field->getCharacterDataList(); 
            }
        }
        
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

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) && verif_moov.first == true) {

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
            Vector2 origin;
            origin.x=0; origin.y=0;
            Rectangle RS; RS.x = 0; RS.y = texture.height/13;
            RS.height = texture.height/13; RS.width = texture.width/6;
            if(equipe == Blue) {
            
                playerTileX = playerPosition.x;
                playerTileY = playerPosition.y;
                Rectangle Rdest; Rdest.x = playerTileX; Rdest.y = playerTileY;
                Rdest.height = PLAYER_SIZE; Rdest.width = PLAYER_SIZE;
                switch (le_type) {
                    case Support:
                        //DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, PINK);
                        RS.y = RS.y*5;
                        //DrawTextureRec(texture,RT,pos,WHITE);
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    case Tank:
                        //DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, RED);
                        //Rectangle RT; RT.x = 0; RT.y = texture.height/13;
                        //RT.height = texture.height/13; RT.width = texture.width/6;
                        //DrawTextureRec(texture,RT,pos,WHITE);                       
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    case Melee:
                        //DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, BLUE);
                        RS.y = RS.y*2;
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    case Sorcerer:
                        //DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, GRAY);
                        RS.y=RS.y*4;
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    case Archer:
                        //DrawRectangle(playerTileX, playerTileY, PLAYER_SIZE, PLAYER_SIZE, GREEN);
                        RS.y=RS.y*3;
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
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

        
        Rectangle destination;
        destination.x = PosXPink;
        destination.y = 650;
        destination.width = Width * 0.10;
        destination.height = Width * 0.10;
        Rectangle ImT; /* permet de récupérer l'image pour le Tank*/
        ImT.x = 0; ImT.y = texture.height/13;
        ImT.height = texture.height/13; ImT.width = texture.width/6;
        Vector2 origine;
        origine.x = 0; origine.y = 0;
        /*dessine le healer*/
        Rectangle ImH = ImT; 
        ImH.y = 5*ImH.y; /* permet de récupérer l'image pour le healer*/
        DrawTexturePro(texture,ImH,destination,origine,0,WHITE);
        //DrawRectangle(PosXPink, 650, Width * 0.10 , Width * 0.10 , PINK);

        /*dessine le tank*/
        Rectangle destTank = destination;
        destTank.x = PosXRed;
        DrawTexturePro(texture,ImT,destTank,origine,0,WHITE);
        /*dessine le melee*/
        Rectangle ImM = ImT; 
        ImM.y = ImM.y*2; /* permet de récupérer l'image pour le Melee*/
        Rectangle destMelee = destination;
        destMelee.x = PosXBlue;
        DrawTexturePro(texture,ImM,destMelee,origine,0,WHITE);

        /*dessine l'archer'*/
        Rectangle ImA = ImT; 
        ImA.y = ImA.y * 3; /* permet de récupérer l'image pour l'archer'*/
        Rectangle destArcher = destination;
        destArcher.x = PosXGreen;
        DrawTexturePro(texture,ImA,destArcher,origine,0,WHITE);

        /*dessine le Sorcerer*/
        Rectangle ImS = ImT; 
        ImS.y = ImS.y*4; /* permet de récupérer l'image pour le Melee*/
        Rectangle destSorc = destination;
        destSorc.x = PosXGray;
        DrawTexturePro(texture,ImS,destSorc,origine,0,WHITE);
        //DrawRectangle(PosXGreen, 650, Width * 0.10 , Width * 0.10 , GREEN);
        //DrawRectangle(PosXRed, 650, Width * 0.10 , Width * 0.10 , RED);
        //DrawRectangle(PosXGray, 650, Width * 0.10 , Width * 0.10 , GRAY);
        //DrawRectangle(PosXBlue, 650, Width * 0.10 , Width * 0.10 , BLUE);            
        //void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);
        //Le Banc
        DrawLine(0, 650, screenWidth, 650, BLACK );
        DrawLine(0, 550, screenWidth, 550, BLACK );
        
        //delimitation des deux camps enemis
        DrawLine(0,225, screenWidth, 225, RED);
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