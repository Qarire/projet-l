#include "Brain.h"

Brain::Brain(CharacterData* charac, vector<Action*> list){
    character = charac;
    actionlist = list;
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


pair<int,CharacterData*> Brain::FindpairCharacterDistance(CharacterData* charac, int heightTerrain, int widthTerrain){
    int dist;
    pair<int,CharacterData*> p;

    for(int i=0; i<heightTerrain;i++) {
        for(int j=0;j<widthTerrain;j++)
        {
            if(charac->getPos().getX() == i && charac->getPos().getY() == j) {
                dist=sqrt(i*i + j*j);
            }
        }
    }
    p.first = dist;
    p.second = charac;

    return p;
}

// Action Brain::findPriority(CharacterData* charac,vector<Action> listaction) {
    
// }


void Brain::Update(float dt) {
    
}
