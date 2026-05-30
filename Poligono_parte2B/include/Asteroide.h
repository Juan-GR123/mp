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
    PoliReg roca ;
    Punto2D veloc ;
    float giro;
public:
    Asteroide();
    Asteroide(const PoliReg & pol, const Punto2D & vel,float rads=10);
    void mover();
    void rotar();
    bool colision(const Asteroide & otro) const;
    Punto2D getVelocidad() const;
    PoliReg getRoca() const;
    void setVelocidad(const Punto2D & nuevaVel);
    void pintar_asteroide() const;
    void choque_Asteroides(Asteroide & otro);
    void choque_borde();
    bool fueraPantalla() const;
    void mover_roca(float x, float y);
    
    
    friend ostream& operator<<(ostream &flujo, const Asteroide &otro);
    
};

#endif /* ASTEROIDE_H */

