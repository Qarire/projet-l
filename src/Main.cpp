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

    Field* field = Field::GetInstance();
    Game* game = Game::GetInstance();
    Updater* updater = Updater::GetInstance();
    Drawer* drawer = Drawer::GetInstance();

    int display = GetCurrentMonitor();

    int screenWidth = GetMonitorWidth(display);
    int screenHeight = GetMonitorHeight(display);
    InitWindow(screenWidth, screenHeight, "Game Window");
    Texture2D texture = LoadTexture("img/Sprite.png");

    //ToggleFullscreen();

    pair<bool, CharacterData*> verif_moov;
    Vector2 My_Mouse;
       
    int width35 = screenWidth * 0.35;
    int width25 = screenWidth * 0.25;

    Rectangle tankButtonRect = Rectangle{float(GetScreenWidth()/6 * 1), float(GetScreenHeight() * 0.87), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};
    Rectangle meleeButtonRect = Rectangle{float(GetScreenWidth()/6 * 2), float(GetScreenHeight() * 0.87), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};
    Rectangle archerButtonRect = Rectangle{float(GetScreenWidth()/6 * 3), float(GetScreenHeight() * 0.87), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};
    Rectangle sorcererButtonRect = Rectangle{float(GetScreenWidth()/6 * 4), float(GetScreenHeight() * 0.87), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};
    Rectangle healerButtonRect = Rectangle{float(GetScreenWidth()/6 * 5), float(GetScreenHeight() * 0.87), float(GetScreenWidth()*0.05), float(GetScreenWidth()*0.05)};

    vector<Event*> events = {
        new Event(new ButtonCondition(tankButtonRect), new ConsequenceInvoque(Tank)),
        new Event(new ButtonCondition(meleeButtonRect), new ConsequenceInvoque(Melee)),
        new Event(new ButtonCondition(archerButtonRect), new ConsequenceInvoque(Archer)),
        new Event(new ButtonCondition(sorcererButtonRect), new ConsequenceInvoque(Sorcerer)),
        new Event(new ButtonCondition(healerButtonRect), new ConsequenceInvoque(Healer)),
    };  

    field->Init(make_pair(25, 25));
    game->Init(); drawer->Init();
    updater->Init(new Behavior( events ));  

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime(); // delta time since last frame
        My_Mouse = GetMousePosition();

        updater->Update(dt);

        BeginDrawing();
        
            ClearBackground(RAYWHITE);

            //Le Banc
            DrawLine(0, float(GetScreenHeight() * 0.8333), float(GetScreenWidth()), float(GetScreenHeight() * 0.8333), BLACK );
            DrawLine(0, float(GetScreenHeight() * 0.7222), float(GetScreenWidth()), float(GetScreenHeight() * 0.7222), BLACK );

            //delimitation des deux camps enemis
            DrawLine(0, float(GetScreenHeight() * 0.3611), float(GetScreenWidth()), float(GetScreenHeight() * 0.3611), RED);

            DrawTexturePro(
                texture,
                Rectangle{0, float(1.0 * texture.height/14.0), float(texture.height/14.0), float(texture.width/6.0)},
                tankButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                texture,
                Rectangle{0, float(2.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                meleeButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                texture,
                Rectangle{0, float(3.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                archerButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                texture,
                Rectangle{0, float(4.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                sorcererButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                texture,
                Rectangle{0, float(5.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                healerButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );


            for(int i = 0; i < field->getCharacterDataList().size(); i++) {
                Type type = field->getCharacterDataList()[i]->getType();
                cout << "[" << field->getCharacterDataList()[i]->getPosition().y << "; " << field->getCharacterDataList()[i]->getPosition().x << "]" << endl;

                switch(type) {
                    case Tank:
                        DrawTextureRec(
                            texture,
                            Rectangle{0, float(1.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                            field->getCharacterDataList()[i]->getPosition().toVector2(),
                            WHITE
                        );
                        break;
                    case Melee:
                        DrawTextureRec(
                            texture,
                            Rectangle{0, float(2.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                            field->getCharacterDataList()[i]->getPosition().toVector2(),
                            WHITE
                        );
                        break;
                    case Archer:
                        DrawTextureRec(
                            texture,
                            Rectangle{0, float(3.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                            field->getCharacterDataList()[i]->getPosition().toVector2(),
                            WHITE
                        );
                        break;
                    case Sorcerer:
                        DrawTextureRec(
                            texture,
                            Rectangle{0, float(4.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                            field->getCharacterDataList()[i]->getPosition().toVector2(),
                            WHITE
                        );
                        break;
                    case Healer:
                        DrawTextureRec(
                            texture,
                            Rectangle{0, float(5.0 * texture.height/14), float(texture.height/14), float(texture.width/6)},
                            field->getCharacterDataList()[i]->getPosition().toVector2(),
                            WHITE
                        );
                        break;
                }
            }


        EndDrawing(); 
    }

    UnloadTexture(texture);

    CloseWindow(); 

    return 0;
}