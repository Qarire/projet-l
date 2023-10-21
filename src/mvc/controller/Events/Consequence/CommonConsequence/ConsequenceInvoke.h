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

        Position pos = Position(
            GetScreenHeight() * 0.8, 
            GetScreenHeight() / field->getCharacterDataList().size() 
                + (GetScreenHeight() / field->getCharacterDataList().size()) 
                    * field->getCharacterDataList().size()
        );

        CharacterData* characd;
        switch (this->type) {
            Tank:
                characd = new CharacterDataTank(Blue, pos);
                break;
            Melee:
                characd = new CharacterDataMelee(Blue, pos);
                break;
            Archer:
                characd = new CharacterDataArcher(Blue, pos);
                break;
            Sorcerer:
                characd = new CharacterDataSorcerer(Blue, pos);
                break;
            Support:
                characd = new CharacterDataSupport(Blue, pos);
                break;
        }

        field->addCharacterData(characd);
    }
};
