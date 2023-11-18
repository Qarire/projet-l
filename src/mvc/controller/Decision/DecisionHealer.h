
#include "Decision"

class DecisionHealer : public Decision {

    public:
    DecisionHealer(characterData* character, vector<Action*> actionlist) : Decision(character,actionlist) {}
    ~DecisionHealer() {} 


    Action* prioritySystem() override {
        
        vector<CharacterData*> listcharactersRange = field->findAllCharacterData(this.character,3);
        vector<CharacterData*> listcharacters = field->findAllCharacterData(this.character->getTeam())
        CharacterData lowcharacter;
        
        if(listcharactersRange.size()==0) {                  /// si pas d'enemie proche à taper
            lowcharacter = field->findLowCharacterData(listcharacters);
            
            return new MouvementSimple(this.character->getPosition(),lowcharacter->getPosition());

        }
        lowcharacter = field->findLowCharacterData(listcharactersRange);
        return new AttackHeal(this.character,lowcharacter);
         
    }
}