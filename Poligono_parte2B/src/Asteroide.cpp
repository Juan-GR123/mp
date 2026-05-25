/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   Asteroide.cpp
 * Author: juan
 *
 * Created on 25 de mayo de 2026, 18:42
 */

#include <cstdlib>
#include "Asteroide.h"
#include <iostream>
#include <string>
#include <cmath>

const bool DEBUG = false;

using namespace std;

/*
 * 
 */
const int Asteroide::MAX_AST = 10;
const int Asteroide::MAX_DIS = 10;
const int Asteroide::max_X = 200;
const int Asteroide::max_Y = 200;

    Asteroide::Asteroide(){
        int n_vertices = rand() % (200 - 3 + 1) + 3; // el max_vert y el min_vert de PoliReg.h como lo llamo en Asteroide?
        float r= rand() % (200 - 15 + 1) + 15;
        Punto2D centro1(rand()% max_X, rand() % max_Y);
        float vx = (rand() % (2 * max_X + 1)) - max_X; // lo tengo que poner a radianes o como?
        float vy = (rand() % (2 * max_Y + 1)) - max_Y;
        
        veloc = Punto2D(vx, vy);
        roca = PoliReg(n_vertices, centro1, r);
        giro = rand() % max_X;
        
    }
    
    Asteroide::Asteroide(const PoliReg & pol, const Punto2D & vel,float rads){
        roca = pol;
        veloc = vel;
        giro = rads;
    }
    void Asteroide::mover(){
        roca.mover(veloc.getX(),veloc.getY());//cojemos los puntos de veloc para que se mueva a la velocidad asignada
    }
    void Asteroide::rotar(){
        roca.rotar(giro);
    }
    bool Asteroide::colision(const Asteroide & otro){
        return roca.colision(otro.roca);
    }
    
    Punto2D Asteroide::getVelocidad() const {
        return veloc;
    }
    
    void Asteroide::setVelocidad(const Punto2D & nuevaVel){
        veloc = nuevaVel;
    }

    
