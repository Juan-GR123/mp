/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Asteroide.h
 * Author: juan
 *
 * Created on 25 de mayo de 2026, 18:42
 */


#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "Punto2D.h"
#include "PoliReg.h"
#include <iostream>
#include <cmath>

using namespace std;


class Asteroide {
private:
    static const int max_X;
    static const int max_Y;
    PoliReg roca ;
    Punto2D veloc ;
    float giro;
    
public:
    static const int MAX_AST;
    static const int MAX_DIS;
    Asteroide();
    Asteroide(const PoliReg & pol, const Punto2D & vel,float rads=10);
    void mover();
    void rotar();
    bool colision(const Asteroide & otro);
    Punto2D getVelocidad() const;
    void setVelocidad(const Punto2D & nuevaVel);
    
};

#endif /* ASTEROIDE_H */

