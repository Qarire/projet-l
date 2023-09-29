#include "Brain.h"

Brain::Brain(CharacterData charac, vector<Action> list){
    character = charac;
    actionlist = list;
}

CharacterData Brain::getCharacter() const {
    return character;
}

void Brain::setCharacterData(CharacterData c) {
    character = c;
}

vector<Action> Brain::getActionlist() const {
    return actionlist;
}


void Brain::Update(float dt) {
    
}
