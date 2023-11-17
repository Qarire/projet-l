#pragma once

#include <string>
#include "Field.h"
#include "Consequence.h"
#include "Sprite.h"
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
        Drawer* drawer = Drawer::GetInstance();

        Position position = Position(0, 0);

        
        CharacterData* characd;
        std::string spriteName;
        switch (this->type) {
            case Tank:
                characd = new CharacterDataTank(Blue, position);
                spriteName = "Tank_icon";
                break;
            case Melee:
                characd = new CharacterDataMelee(Blue, position);
                spriteName = "Melee_icon";
                break;
            case Archer:
                characd = new CharacterDataArcher(Blue, position);
                spriteName = "Archer_icon";
                break;
            case Sorcerer:
                characd = new CharacterDataSorcerer(Blue, position);
                spriteName = "Sorcerer_icon";
                break;
            case Healer:
                characd = new CharacterDataHealer(Blue, position);
                spriteName = "Healer_icon";
                break;
            default:
                throw std::invalid_argument("The type isn't supported");
                break;
        }
        field->addCharacterData(characd);
        Sprite* sprite = new Sprite(spriteName, characd, Position(0, Background::getNegativeFieldWidth() /2));
        drawer->addDrawable(sprite);


        for(int i = 0; i < field->getCharacterDataList().size(); i++) {
            field->getCharacterDataList()[i]->setPosition(
                Position(0, 0)
            );
        }        
    }
};
