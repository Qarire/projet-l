#pragma once

#include "Field.h"
#include "Consequence.h"
#include "Type.h"
#include "Stats.h"

class ConsequenceInvoque : public Consequence {
private:
    Type type;

public:
    ConsequenceInvoque(Type type) {
        this->type = type;
    }

// Public Methods
    void run() override {
        Field* field = Field::GetInstance();

        Position position = Position(GetScreenHeight()*0.75, 0);


        CharacterData* characd;
        switch (this->type) {
            case Tank:
                characd = new CharacterDataTank(Blue, position);
                break;
            case Melee:
                characd = new CharacterDataMelee(Blue, position);
                break;
            case Archer:
                characd = new CharacterDataArcher(Blue, position);
                break;
            case Sorcerer:
                characd = new CharacterDataSorcerer(Blue, position);
                break;
            case Healer:
                characd = new CharacterDataHealer(Blue, position);
                break;
            default:
                throw std::invalid_argument("The type isn't supported");
                break;
        }

        field->addCharacterData(characd);



        for(int i = 0; i < field->getCharacterDataList().size(); i++) {
            field->getCharacterDataList()[i]->setPosition(
                Position(0, 0)
            );
        }        
    }
};
