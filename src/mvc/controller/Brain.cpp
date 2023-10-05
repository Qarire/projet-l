#include "Brain.h"

Brain::Brain(CharacterData* charac, vector<Action*> list){
    character = charac;
    actionlist = list;
}

Brain::~Brain() {
    delete character;

    for(int i = 0; i < actionlist.size(); i++) {
        delete actionlist[i];
    }
    actionlist.clear();
}

CharacterData* Brain::getCharacterData() const {
    return character;
}

void Brain::setCharacterData(CharacterData* c) {
    character = c;
}

vector<Action*> Brain::getActionlist() const {
    return actionlist;
}


// Action Brain::findPriority(CharacterData* charac,vector<Action> listaction) {
    
// }


void Brain::Update(float dt) {
    
}
