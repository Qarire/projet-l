#pragma once
#include <iostream>

struct Position {
    private :
        float x,y; /** @brief les coordonnees en x et en y de notre Position*/
    public : 
        Position ();
    
        Position(float y, float x);
        ~Position();
    
        float getX() const;
        float getY() const;
        void setX(float x);

        void setY(float y);

        bool operator==(Position p);

        Position operator+(Position p);

        Position operator+(float a);
    
        Position operator-(Position p);
    
        Position operator-(float a);
};