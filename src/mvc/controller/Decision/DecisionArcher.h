#include "Decision"
/*
class DecisionArcher : public Decision {

    public:
    DecisionArcher(characterData* character, vector<Action*> actionlist) : Decision(character,actionlist) {}
    ~DecisionArcher() {} 


    Action* prioritySystem() override {
        
        vector<CharacterData*> listcharactersRange = field->findAllCharacterData(this.character,6);
        vector<CharacterData*> listcharacters2 = field->findAllCharacterData(this.character,3);
        CharacterData farcharacter = field->findFarCharacterData(listcharactersRange);
        CharacterData closestcharacter = field->findClosestCharacter(listcharacter);
        
        if(listcharactersRange.size()!=0) {                  /// si pas d'enemie proche à taper
            if(listcharacters2.size()== 0) {
                return new Range(this.character,farcharacter);
            }else
                //return MouvementArcher(this.character->getPosition(),closestcharacter->getPosition);
            
        }
        return new MouvementSimple(this.character->getPosition(),farcharacter->getPosition());
         
    }
}
*/