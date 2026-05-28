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
#include "raylib.h"
#include "configuracion.h"
#include <iostream>
#include <string>
#include <cmath>

const bool DEBUG = true;

using namespace std;

/*
 * 
 */


    Asteroide::Asteroide(){
        int n_vertices = rand() % (max_ver - min_ver + 1) + min_ver; 
        float r= rand() % (max_radio - min_radio + 1) + min_radio;
        Punto2D centro1(rand()% max_X, rand() % max_Y);
        float vx = rand() % (max_vel - min_vel + 1) + min_vel;
        float vy = rand() % (max_vel - min_vel + 1) + min_vel;
        
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
    bool Asteroide::colision(const Asteroide & otro) const{
        return roca.colision(otro.roca);
    }
    
    Punto2D Asteroide::getVelocidad() const {
        return veloc;
    }
    
    PoliReg Asteroide::getRoca() const{
        return roca;
    }
    
    void Asteroide::setVelocidad(const Punto2D & nuevaVel){
        veloc = nuevaVel;
    }
    
    void Asteroide::choque_Asteroides(Asteroide & otro){
        Punto2D v1 = this->veloc;
        Punto2D v2 = otro.veloc;
        
        this->veloc= v2;
        otro.veloc = v1;
        
    }
    
  
    
    void Asteroide::choque_borde(){
        if ((this->roca.getCentro().getX() >= (max_X - roca.getRadio())) || (this->roca.getCentro().getX() <= this->roca.getRadio()))
		this->veloc.setX(this->veloc.getX() * -1.1 );
	if ((this->roca.getCentro().getY() >= (max_Y - roca.getRadio())) || (this->roca.getCentro().getY() <= this->roca.getRadio()))
		this->veloc.setY(this->veloc.getY() * -1.1);
    }
    
    bool Asteroide::fueraPantalla() const{

        bool respuesta = false;
        float x = roca.getCentro().getX();
        float y = roca.getCentro().getY();
        float r = roca.getRadio();

        if (( x >= (max_X - r)) || (x <= r) || (y >= max_Y - r) || (y <= r )){
            respuesta = true;
        }
        
        return respuesta;
    }
    
     ostream& operator<<(ostream &flujo, const Asteroide &otro){
         flujo << "@roca " << otro.roca << "\n@veloc " << otro.veloc << "\ngiro " << otro.giro << endl;
         
         return flujo;
     }
    
    
    

    
