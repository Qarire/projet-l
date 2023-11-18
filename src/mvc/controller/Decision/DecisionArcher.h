#include "Decision"

class DecisionArcher : public Decision {

    public:
    DecisionArcher(characterData* character, vector<Action*> actionlist) : Decision(character,actionlist) {}
    ~DecisionArcher() {} 


    Action* prioritySystem() override {
        
        vector<CharacterData*> listcharactersRange = field->findAllCharacterData(this.character,6);
        vector<CharacterData*> listcharacters2 = field->findAllCharacterData(this.character,3);
        CharacterData farcharacter;
        CharacterData closestcharacter;
        
        if(listcharactersRange.size()!=0) {                  /// si pas d'enemie proche à taper
            
            if(listcharacters2.size()== 0) {
                farcharacter = field->findFarCharacterData(listcharactersRange,listcharactersRange);
                return new Range(this.character,farcharacter);
            }else
                closestcharacter = field->findClosestCharacter(listcharacter);
                //return MouvementArcher(this.character->getPosition(),closestcharacter->getPosition); // Ce serait un mouvement pour la fuite
            
        }
        return new MouvementSimple(this.character->getPosition(),farcharacter->getPosition());
         
    }
}
