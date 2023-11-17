
#include "Decision"

class DecisionMelee : public Decision {

    public:
    DecisionMelee(characterData* character, vector<Action*> actionlist) : Decision(character,actionlist) {}
    ~DecisionMelee() {} 


    Action* prioritySystem() override {
        
        vector<CharacterData*> listcharactersRange = field->findAllCharacterData(this.character,1);
        vector<CharacterData*> listcharacters = field->findAllCharacterData(this.character->getTeam())
        CharacterData weakcharacter;
        CharacterData closestcharacter;
        
        if(listcharactersRange.size()>= 2) {                  /// si pas d'enemie proche à taper
            weakcharacter = field->findWeakCharacterData(listcharactersRange);
            
            return new Mouvement(this.character->getPosition(),weakcharacter->getPosition());

        }else if (listcharatersRange.size()==0) {
            closestcharacter = field->findClosestCharacter(this.character);
            return new Mouvement(this.character->getPostion(),closestcharacter->getPosition());
        }
        return new AttackHeal(this.character,listcharactersRange[0]);
         
    }
}