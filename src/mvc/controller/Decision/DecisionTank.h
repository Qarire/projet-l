
#include "Decision"

class DecisionTank : public Decision {

    public:
    DecisionTank(characterData* character, Action* actionlist) : Decision(character,actionlist) {}
    ~DecisionTank() {} 


    Action* prioritySystem() override {
        
        vector<CharacterData*> listcharacters = field->findAllCharacterData(this.character,1);
        vector<CharacterData*> listbehindcharacter;
        CharacterData* closecharacter;
        

        if(listcharacters.size()==0) {                  /// si pas d'enemie proche à taper
            listbehindcharacter = field->findAllbehindCharacterData(this.character);
            
            if(behindcharacter.size()==0) {                 /// si pas d'enemie derriere 
                closecharacter = field->findClosestCharacter(this.character);
                return new MouvementSimple(this.character->getPosition(),closecharacter->getPosition());
            } 
            closecharacter = field->findClosestCharacter(this.character,listbehindcharacter)
            return new MouvementSimple(this.character->getPostion(),closecharacter->getPosition());

        }
        
        return new Melee(this.character,listcharacters[0]);
         
    }
}