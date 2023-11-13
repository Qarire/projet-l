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
#include "ButtonCondition.h"
#include "ConsequenceInvoke.h"


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
    Team first_team = Red;
    Team seconde_team = Blue;


    pair<bool, CharacterData*> verif_moov;

    Vector2 My_Mouse;

    int width35 = screenWidth * 0.28;
    int width25 = screenWidth * 0.1;

    int PosXPink = width35;
    int PosXGreen = PosXPink + width25;
    int PosXRed = PosXGreen + width25;
    int PosXGray = PosXRed + width25;
    int PosXBlue = PosXGray + width25;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        My_Mouse = GetMousePosition();

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ) {

            int it = field->getCharacterDataList().size();

            if ((My_Mouse.x > PosXPink && My_Mouse.x < PosXPink + screenWidth* 0.05) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.05  )) {
                CharacterData* new_Support_perso = new CharacterData(seconde_team,stat_perso, Position(screenHeight * 0.775,100 + it * 100),23,44,Support,Support);
                field->addCharacterData(new_Support_perso);
            }

            if ((My_Mouse.x > PosXGreen && My_Mouse.x < PosXGreen + screenWidth * 0.05) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.05  )) {
                CharacterData* new_archer_perso = new CharacterData(seconde_team,stat_perso,Position(screenHeight * 0.775,100 + it * 100),23,44,Archer,Tank);
                field->addCharacterData(new_archer_perso);
            }

            if ((My_Mouse.x > PosXRed && My_Mouse.x < PosXRed + screenWidth * 0.05) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.05  )) {
                CharacterData* new_Tank_perso = new CharacterData(seconde_team,stat_perso, Position(screenHeight * 0.775 ,100 + it * 100),23,44,Tank,Tank);
                field->addCharacterData(new_Tank_perso);
            }

            if ((My_Mouse.x > PosXGray && My_Mouse.x < PosXGray + screenWidth * 0.05) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.05  )) {
                CharacterData* new_Sorcerer_perso = new CharacterData(seconde_team,stat_perso,Position(screenHeight * 0.775,100 + it * 100),23,44,Sorcerer,Melee);
                field->addCharacterData(new_Sorcerer_perso);
            }

            if ((My_Mouse.x > PosXBlue && My_Mouse.x < PosXBlue + screenWidth * 0.05) && (My_Mouse.y > 800  && My_Mouse.y < 800 + screenWidth * 0.05  )) {
                CharacterData* new_Melee_perso = new CharacterData(seconde_team,stat_perso,Position(screenHeight * 0.775,100 + it * 100),23,44,Melee,Tank);
                field->addCharacterData(new_Melee_perso);
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
                        RS.y = RS.y*5;
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    case Tank:
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    case Melee:
                        RS.y = RS.y*2;
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    case Sorcerer:
                        RS.y=RS.y*4;
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    case Archer:
                        RS.y=RS.y*3;
                        DrawTexturePro(texture,RS,Rdest,origin,0,WHITE);
                        break;
                    default:
                        cerr << "error" << endl;
                }
            }


        }

        //Le Banc

        DrawLine(0, screenHeight * 0.8333, screenWidth, 750, BLACK );
        DrawLine(0, screenHeight * 0.7222, screenWidth, 650, BLACK );

        //delimitation des deux camps enemis
        DrawLine(0,screenHeight * 0.3611, screenWidth, 325, RED);

        //Shop
        Rectangle destination;
        destination.x = PosXPink;
        destination.y = 800;
        destination.width = screenWidth * 0.05;
        destination.height = screenWidth * 0.05;
        Rectangle ImT; /* permet de récupérer l'image pour le Tank*/
        ImT.x = 0; ImT.y = texture.height/13;
        ImT.height = texture.height/13; ImT.width = texture.width/6;
        Vector2 origine;
        origine.x = 0; origine.y = 0;
        /*dessine le healer*/
        Rectangle ImH = ImT;
        ImH.y = 5*ImH.y; /* permet de récupérer l'image pour le healer*/
        DrawTexturePro(texture,ImH,destination,origine,0,WHITE);


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


        EndDrawing();
    }

    UnloadTexture(texture);

    CloseWindow();
    //--------------------------------------------------------------------------------------




    return 0;
}
