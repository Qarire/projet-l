#include <iostream>
#include <utility>

#include "Game.h"
#include "Field.h"
#include "Updater.h"
#include "Drawer.h"
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

// Game loop
    // while(true) {
    //     updater->Update(1);
    // }

// Endings
    delete field;
    delete game;
    delete updater;
    delete drawer;
}
