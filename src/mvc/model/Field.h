#pragma once


#include <vector>
#include <utility>

#include "CharacterData.h"


class Field {
private:
//! Singleton
    Field() {}
    static Field* Instance;
//! Singleton


// Fields
    vector<CharacterData*> CharacterDataList;
    pair<int, int> size;


// Private Methods

    int findCharacterDataIndex(CharacterData* data) {
        for(int i=0; i<CharacterDataList.size(); i++) {
            if(CharacterDataList[i] == data)
                return i;
        }

        throw std::invalid_argument("This CharacterData does not exists on the Field");
    }


public:
//! Singleton
    static Field* GetInstance() { 
        if(Instance == nullptr)
            Instance = new Field();
        
        return Instance;
    } 
//! Singleton

    void Init(pair<int, int> size) {
        this->size = size;
    }


// Public Methods
    int getHeight() const { 
        return size.first;
    }
    int getWidth() const { 
        return size.second;
    }

    vector<CharacterData*> getCharacterDataList() const {
        return CharacterDataList;
    }    

    void addCharacterData(CharacterData* data) {
        CharacterDataList.push_back(data);
    }
    void removeCharacterData(CharacterData* data) {
        int index = findCharacterDataIndex(data);

        CharacterDataList.erase(CharacterDataList.begin() + index);
    }

};