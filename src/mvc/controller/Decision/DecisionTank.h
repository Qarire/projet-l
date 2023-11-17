
#include "Decision"

class DecisionTank : public Decision {

    public:
    DecisionTank(characterData* character, Action* actionlist) : Decision(character,actionlist) {}
    ~DecisionTank() {} 


    Action* prioritySystem() override {
        
        vector<CharacterData*> listcharacters;
        CharacterData closecharacter;
        CharacterData behindcharacter;
        listcharacters=field->findAllCharacterData(this.character,1);

        
        if(listcharacters.size()==0) {                  /// si pas d'enemie proche à taper
            behindcharacter = field->findAllbehindCharacterData(this.character);
            
            if(behindcharacter.size()==0) {                 /// si pas d'enemie derriere 
                closecharacter = field->findClosestCharacter(this.character);
                //return new Mouvement(closecharacter->getPosition());
            } 

            //return new Mouvement(behindcharacter->getPosition());

        }
        
        return new Melee(this.character,listcharacters[0]);
         
    }
}