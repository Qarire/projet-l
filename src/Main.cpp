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
    // Setting up the code

    Field* field = Field::GetInstance();
    Game* game = Game::GetInstance();
    Updater* updater = Updater::GetInstance();
    Drawer* drawer = Drawer::GetInstance();

    // Setting up the window
    int display = GetCurrentMonitor();

    int screenWidth = GetMonitorWidth(display);
    int screenHeight = GetMonitorHeight(display);

    InitWindow(screenWidth, screenHeight, "Game Window");

    Texture2D spriteTexture = LoadTexture("img/Sprite.png");
    Texture2D groundSpriteTexture = LoadTexture("img/Ground_Sprite.png");

    //ToggleFullscreen();


    // creating the events
    pair<bool, CharacterData*> verif_moov;
    Vector2 My_Mouse;

    float diff = (GetScreenWidth() - (float(GetScreenWidth()/6) + float(GetScreenWidth()/8) * 6)) / 4;

    Rectangle deleteRectangle =     Rectangle{diff + float(GetScreenWidth()/6 * 0), float(GetScreenHeight() * 0.75), float(GetScreenWidth()/8), float(GetScreenWidth()/8)};
    Rectangle tankButtonRect =      Rectangle{diff + float(GetScreenWidth()/6 * 1), float(GetScreenHeight() * 0.75), float(GetScreenWidth()/8), float(GetScreenWidth()/8)};
    Rectangle meleeButtonRect =     Rectangle{diff + float(GetScreenWidth()/6 * 2), float(GetScreenHeight() * 0.75), float(GetScreenWidth()/8), float(GetScreenWidth()/8)};
    Rectangle archerButtonRect =    Rectangle{diff + float(GetScreenWidth()/6 * 3), float(GetScreenHeight() * 0.75), float(GetScreenWidth()/8), float(GetScreenWidth()/8)};
    Rectangle sorcererButtonRect =  Rectangle{diff + float(GetScreenWidth()/6 * 4), float(GetScreenHeight() * 0.75), float(GetScreenWidth()/8), float(GetScreenWidth()/8)};
    Rectangle healerButtonRect =    Rectangle{diff + float(GetScreenWidth()/6 * 5), float(GetScreenHeight() * 0.75), float(GetScreenWidth()/8), float(GetScreenWidth()/8)};

    vector<Event*> events = {
        new Event(new ButtonCondition(tankButtonRect),      new ConsequenceInvoque(Tank)),
        new Event(new ButtonCondition(meleeButtonRect),     new ConsequenceInvoque(Melee)),
        new Event(new ButtonCondition(archerButtonRect),    new ConsequenceInvoque(Archer)),
        new Event(new ButtonCondition(sorcererButtonRect),  new ConsequenceInvoque(Sorcerer)),
        new Event(new ButtonCondition(healerButtonRect),    new ConsequenceInvoque(Healer)),
    };  

    // starting up the game
    field->Init(make_pair(8, 7));
    game->Init(); drawer->Init();
    updater->Init(new Behavior( events ));  


    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose()) {
        float dt = GetFrameTime(); // delta time since last frame
        My_Mouse = GetMousePosition();

        updater->Update(dt);

        BeginDrawing();
        
            ClearBackground(RAYWHITE);

            // Background
            for(int i = 0; i < GetScreenHeight()/field->getFieldTile(); i++) {
                for(int j = 0; j < GetScreenWidth()/field->getFieldTile(); j++) {
                    DrawTexturePro(
                        groundSpriteTexture,
                        Rectangle{0, 0, float(groundSpriteTexture.width), float(groundSpriteTexture.height/5)},
                        Rectangle{j * field->getFieldTile(), i * field->getFieldTile(), field->getFieldTile(), field->getFieldTile()},
                        Vector2{0, 0},
                        0,
                        WHITE
                    );
                }
            }
            

            for(int i = 0; i < field->getHeight(); i++) {
                for(int j = 0; j < field->getWidth(); j++) {
                    DrawTexturePro(
                        spriteTexture,
                        Rectangle{0, 0, float(spriteTexture.height/14.0), float(spriteTexture.width/11.0)},
                        Rectangle{ field->getNegativeFieldWidth() / 2 + j * field->getFieldTile(), i * field->getFieldTile(), field->getFieldTile(), field->getFieldTile()},
                        Vector2{0, 0},
                        0,
                        WHITE
                    );
                }
            }

            

            //Le Banc
            // DrawLine(0, float(GetScreenHeight() * 0.8333), float(GetScreenWidth()), float(GetScreenHeight() * 0.8333), BLACK );
            // DrawLine(0, float(GetScreenHeight() * 0.7222), float(GetScreenWidth()), float(GetScreenHeight() * 0.7222), BLACK );

            //delimitation des deux camps enemis
            // DrawLine(0, float(GetScreenHeight() * 0.3611), float(GetScreenWidth()), float(GetScreenHeight() * 0.3611), RED);

            DrawTexturePro(
                spriteTexture,
                Rectangle{float(6.0 * spriteTexture.width/11.0), float(10.0 * spriteTexture.height/14.0), float(spriteTexture.height/14.0 *2), float(spriteTexture.width/11.0 *2)},
                deleteRectangle,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                spriteTexture,
                Rectangle{float(6.0 * spriteTexture.width/11.0), float(0.0 * spriteTexture.height/14.0), float(spriteTexture.height/14.0 *2), float(spriteTexture.width/11.0 *2)},
                tankButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                spriteTexture,
                Rectangle{float(6.0 * spriteTexture.width/11.0), float(2.0 * spriteTexture.height/14), float(spriteTexture.height/14 *2), float(spriteTexture.width/11.0 *2)},
                meleeButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                spriteTexture,
                Rectangle{float(6.0 * spriteTexture.width/11.0), float(4.0 * spriteTexture.height/14), float(spriteTexture.height/14 *2), float(spriteTexture.width/11.0 *2)},
                archerButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                spriteTexture,
                Rectangle{float(6.0 * spriteTexture.width/11.0), float(6.0 * spriteTexture.height/14), float(spriteTexture.height/14 *2), float(spriteTexture.width/11.0 *2)},
                sorcererButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );
            DrawTexturePro(
                spriteTexture,
                Rectangle{float(6.0 * spriteTexture.width/11.0), float(8.0 * spriteTexture.height/14), float(spriteTexture.height/14 *2), float(spriteTexture.width/11.0 *2)},
                healerButtonRect,
                Vector2{0, 0},
                0,
                WHITE
            );


            for(int i = 0; i < field->getCharacterDataList().size(); i++) {
                Type type = field->getCharacterDataList()[i]->getType();
                cout << "[" << field->getCharacterDataList()[i]->getPosition().y << "; " << field->getCharacterDataList()[i]->getPosition().x << "]" << endl;

                Rectangle source;
                switch(type) {
                    case Tank:
                        source = Rectangle{0, float(1.0 * spriteTexture.height/14), float(spriteTexture.height/14), float(spriteTexture.width/11.0)};
                        break;
                    case Melee:
                        source = Rectangle{0, float(2.0 * spriteTexture.height/14), float(spriteTexture.height/14), float(spriteTexture.width/11.0)};
                        break;
                    case Archer:
                        source = Rectangle{0, float(3.0 * spriteTexture.height/14), float(spriteTexture.height/14), float(spriteTexture.width/11.0)};
                        break;
                    case Sorcerer:
                        source = Rectangle{0, float(4.0 * spriteTexture.height/14), float(spriteTexture.height/14), float(spriteTexture.width/11.0)};
                        break;
                    case Healer:
                        source = Rectangle{0, float(5.0 * spriteTexture.height/14), float(spriteTexture.height/14), float(spriteTexture.width/11.0)};
                        break;
                }
                DrawTexturePro(
                    spriteTexture,
                    source,
                    Rectangle{field->getCharacterDataList()[i]->getPosition().y, field->getCharacterDataList()[i]->getPosition().x, field->getFieldTile(), field->getFieldTile()},
                    Vector2{0,0},
                    0,
                    WHITE
                );
            }


        EndDrawing(); 
    }

    UnloadTexture(spriteTexture);
    UnloadTexture(groundSpriteTexture);

    CloseWindow(); 

    return 0;
}