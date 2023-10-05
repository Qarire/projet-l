#pragma once

#include <iostream>

using namespace std;

class Position {
    private :
        float x,y; /** @brief les coordonnees en x et en y de notre Position*/

    public :
        Position();
        /** @brief le constructeur par defaut de notre Position*/
        
        Position(float a, float b);
        /** @brief le constructeur par copie de notre Position*/
       
        ~Position();
        /** @brief le destructeur par defaut du Position*/
        float x const;
        /** @brief permet de recuperer la coordonnee x du Position*/
        float y const;
        /** @brief permet de recuperer la coordonnee y du Position*/
        void setX(float x1);
        /** @brief permet de modifier la coordonnee x du Position*/
        void setY(float y1);
        /** @brief permet de modifier la coordonnee y du Position*/
        bool operator==(Position v);
        /** @brief effectue le test d'egalite avec le Position v
        @param le Position v auquel nous voulons comparer notre Position*/
        Position operator+(Position v);
        /** @brief effectue l'addition entre les Positions
        @param le Position v auquel nous voulons ajouter notre Position*/
        Position operator-(Position v);
        /** @brief effectue la soustraction entre les Positions
        @param le Position v avec lequel on soustrait notre Position*/
        Position operator+(float a);
        /** @brief effectue l'addition entre le Position et un reel a
        @param le reel a que l'on ajoute au Position*/
        Position operator-(float a);
        /** @brief effectue la soustraction entre le Position et un reel a
        @param le reel a que l'on retire au Position*/
};

ostream& operator<<(ostream& os, const Position& Position);