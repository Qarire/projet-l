
#include "Decision"

class DecisionMelee : public Decision {

    public:
    DecisionMelee(characterData* character, vector<Action*> actionlist) : Decision(character,actionlist) {}
    ~DecisionMelee() {} 


    Action* prioritySystem() override {
        
        vector<CharacterData*> listcharacters;
        CharacterData closecharacter;
        listcharacters=field->findAllCharacterData(this.character,1);

        if(listcharacters.size()==0) {
            closecharacter = field->findCloserCharacter(this.character);
            //return new Mouvement(this.character->getPosition());
        }else
        
        return new Melee(this.character,listcharacters[0]);
         
    }
}