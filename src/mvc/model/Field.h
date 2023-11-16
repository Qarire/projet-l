#pragma once

#include <iostream>
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
    static Field* GetInstance();
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

// Find Method
    CharacterData* findClosestCharacter(CharacterData* character) {
        vector<CharacterData*> allEnemies = findAllCharacterData(character->getTeam());

        CharacterData* closest = allEnemies[0];

        for(int i = 0; i < allEnemies.size(); i++) {
            if(
                Position::distance(character->getPosition(), allEnemies[i]) 
              < Position::distance(character->getPosition(), closest) 
            ) {
                closest = allEnemies[i];
            }
        }

        return closest;
    }


// Find All... Methods
    vector<CharacterData*> intersectionOfLists(vector<vector<CharacterData*>> listOfLists) {
        vector<CharacterData*> resultList = listOfLists[0];

        for(int i = 1; i < listOfLists.size(); i++) {
            // Compare the content and keep only what's similar:
            vector<CharacterData*> tmpResultList;
            for(int j = 0; j < resultList.size(); j++) {
                for(int k = 0; k < listOfLists[i].size(); k++) {
                    if(listOfLists[i][k] == resultList[j]) 
                        tmpResultList.push_back(listOfLists[i][k]);
                }
            }
            resultList = tmpResultList;
        }

        return resultList;
    }


    vector<CharacterData*> findAllCharacterData(Team team) const {
        vector<CharacterData*> resultList;

        for(int i = 0; i < CharacterDataList.size(); i++) {
            if(CharacterDataList[i]->getTeam() == team)
                resultList.push_back(CharacterDataList[i]);
        }

        return resultList;
    }
    vector<CharacterData*> findAllCharacterData(Type type) const {
        vector<CharacterData*> resultList;

        for(int i = 0; i < CharacterDataList.size(); i++) {
            if(CharacterDataList[i]->getType() == type)
                resultList.push_back(CharacterDataList[i]);
        }

        return resultList;
    }
    vector<CharacterData*> findAllCharacterData(Position position, int range) const {
        vector<CharacterData*> resultList;

        for(int i = 0; i < CharacterDataList.size(); i++) {
            if(range >= Position::distance(position, CharacterDataList[i]->getPosition()))
                resultList.push_back(CharacterDataList[i]);
        }

        return resultList;
    }

};