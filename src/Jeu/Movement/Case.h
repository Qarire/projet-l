#pragma once

#ifndef _CASE_H
#define _CASE_H

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include "Movement.h"

using namespace std;

class Case {
private : 
    Vecteur pos;
    float f_score;
    float h_score;
    float g_score;
    bool accessible;
    Case* parent;

public : 
    Case();
    Case(Vecteur v, float f, float h, float g,bool b, Case* p);
    
	~Case();
    float get_f_score();
    float get_g_score();
    float get_h_score();
    Vecteur get_pos();
    Case* get_parent();
    bool get_accessible();


    void set_f_score(float x);
    void set_g_score(float x);
    void set_h_score(float x);
    void set_parent( Case* case1);
    void set_pos(Vecteur v);
    void set_accessible(bool b);

    
    
};
#endif