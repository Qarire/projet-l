#pragma once

#include <iostream>

using namespace std;

class Vecteur {
    private :
        float x,y; /** @brief les coordonnees en x et en y de notre vecteur*/

    public :
        Vecteur();
        /** @brief le constructeur par defaut de notre vecteur*/
        
        Vecteur(float a, float b);
        /** @brief le constructeur par copie de notre vecteur*/
       
        ~Vecteur();
        /** @brief le destructeur par defaut du vecteur*/
        float getX() const;
        /** @brief permet de recuperer la coordonnee x du vecteur*/
        float getY() const;
        /** @brief permet de recuperer la coordonnee y du vecteur*/
        void setX(float x1);
        /** @brief permet de modifier la coordonnee x du vecteur*/
        void setY(float y1);
        /** @brief permet de modifier la coordonnee y du vecteur*/
        bool operator==(Vecteur v);
        /** @brief effectue le test d'egalite avec le vecteur v
        @param le vecteur v auquel nous voulons comparer notre vecteur*/
        Vecteur operator+(Vecteur v);
        /** @brief effectue l'addition entre les vecteurs
        @param le vecteur v auquel nous voulons ajouter notre vecteur*/
        Vecteur operator-(Vecteur v);
        /** @brief effectue la soustraction entre les vecteurs
        @param le vecteur v avec lequel on soustrait notre vecteur*/
        Vecteur operator+(float a);
        /** @brief effectue l'addition entre le vecteur et un reel a
        @param le reel a que l'on ajoute au vecteur*/
        Vecteur operator-(float a);
        /** @brief effectue la soustraction entre le vecteur et un reel a
        @param le reel a que l'on retire au vecteur*/
};

ostream& operator<<(ostream& os, const Vecteur& vecteur);