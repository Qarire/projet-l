
#include "Decision"

class DecisionTank : public Decision {

    public:
    DecisionTank(characterData* character, vector<Action*> actionlist) : Decision(character,actionlist) {}
    ~DecisionTank() {} 


    Action* prioritySystem() override {
        
        vector<CharacterData*> listcharacters;
        CharacterData closecharacter;
        listcharacters=field->findAllCharacterData(this.character,1);

        if(listcharacters.size()==0) {
            closecharacter = field->findCloserCharacter(this.character);
            //return new Mouvement();
        }else
        
        return new Melee(this.character,listcharacters[0]);
         
    }
}