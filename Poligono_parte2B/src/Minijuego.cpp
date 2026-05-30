/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   Minijuego.cpp
 * Author: juan
 *
 * Created on 28 de mayo de 2026, 16:26
 */

#include <cstdlib>
#include "Minijuego.h"
#include "raylib.h"
#include "configuracion.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
const bool DEBUG = false;
bool gameOver= false;
bool campeon = false;

void Minijuego::liberarMemoria(){
    if (campoAsteroides != nullptr){
        delete[] campoAsteroides;
        campoAsteroides = nullptr;
    }

    if (disparos != nullptr){
        delete[] disparos;
        disparos = nullptr;
    }
}

void Minijuego::generarJuego(){
    campoAsteroides = new Asteroide[MAX_AST];//se crearan por defecto
    uAst = 10; 
    
    disparos = new Asteroide[MAX_DIS];
    uDisp = 0;
   
    Punto2D centroNave(max_X/2, max_Y/1.25);

    PoliReg base(3, centroNave, 15);
    
    Punto2D velNave(0,0);
    
    this->nave = Asteroide(base,velNave, 0); // la nave no tendra velocidad ni giro hasta que se mueva con las teclas de direccion
}

Minijuego::Minijuego(){
    generarJuego();
}

Minijuego::Minijuego(const Asteroide *campo, int nCampo,const Asteroide *disp, int nDisp,const Asteroide &nav){
    campoAsteroides = new Asteroide[MAX_AST];
    uAst = nCampo;
    disparos = new Asteroide[MAX_DIS];
    uDisp=nDisp;
    nave= nav;
}

void Minijuego::disparar(){
    if(uDisp < MAX_DIS){
        float dY= 10;
        Punto2D vel_misil(0,-dY);
        disparos[uDisp] = Asteroide(nave.getRoca(), vel_misil, 0);
        uDisp++;
    }
    
}

void Minijuego::moverYrotar(){
    for(int i=0;i<uAst; i++){
        campoAsteroides[i].mover();
        campoAsteroides[i].rotar();
    }
}

 Asteroide Minijuego::getCampo(int i) const{
     return campoAsteroides[i];
 }
 
 int Minijuego::getuAst() const{
     return uAst;
 }
 
 int Minijuego::getuDisp() const{
     return uDisp;
 }
 
 Asteroide Minijuego::getNave() const{
     return nave;
 }
 
 Asteroide Minijuego::getDisparos(int i) const{
     return disparos[i];
 }

void Minijuego::detectarColisiones_Asteroides(){
    for(int i=0; i <uAst; i++){
        for(int j=i+1; j < uAst; j++){
            if(campoAsteroides[i].colision(campoAsteroides[j])){
                
                if(DEBUG){
                    cout << i << j <<"Antes de intercambiar" << campoAsteroides[i].getVelocidad()  <<  ", " << campoAsteroides[j].getVelocidad() << endl;    
                }
                
        
                campoAsteroides[i].choque_Asteroides(campoAsteroides[j]); 
        
                
                if(DEBUG){
                    cout << i << j << "Despues de intercambiar" << campoAsteroides[i].getVelocidad()  <<  ", " <<  campoAsteroides[j].getVelocidad() << endl;    
                }
                
            }
            
        }
    }
}

void Minijuego::detectarColisiones_bordes(){
     for(int i=0; i<uAst; i++){
        campoAsteroides[i].choque_borde();
    }
}

void Minijuego::detectarMisiles_bordes(){
    for(int i=0; i<uDisp; i++){  

        if(disparos[i].fueraPantalla()){
            
            for(int j=i; j<uDisp-1; j++){//mueve los disparos hacia la izquierda y deja la ultima posicion libre
                disparos[j] = disparos[j+1];
            }
            
            uDisp--; //se quita la ultima posicion
            i--;//se vuelve a revisar la posicion donde se ha borrado el disparo anterior
        }
    }
}

void Minijuego::pintar() const {

    for(int i=0; i<uAst; i++){
        campoAsteroides[i].pintar_asteroide();
    }

    for(int i=0; i<uDisp; i++){
        disparos[i].pintar_asteroide();
    }

    nave.pintar_asteroide();
}

void Minijuego::mover_nave(float x, float y){
    this->nave.mover_roca(x,y);
}

void Minijuego::colision_misiles_Asteroides(){
    for (int i = 0; i < uDisp; i++) {

        bool impacto = false;

        // recorrer asteroides desde el final
        for (int j = uAst - 1; j >= 0 && !impacto; j--) {//si tenemos 10 uAst empezara por j=9 que sera la ultima posicion

            if (disparos[i].colision(campoAsteroides[j])) {

                impacto = true;

                //pasamos a la izquierda los asteroides para poder eliminar la ultima posicion del uAst
                for (int k = j; k < uAst - 1; k++) {
                    campoAsteroides[k] = campoAsteroides[k + 1];
                }
                uAst--;

                i--; // reanalizar posición actual del disparo
            }
        }
    }
}

void Minijuego::detectarColisionNave(){
    for(int i=0; i <uAst; i++){
        if(campoAsteroides[i].colision(this->nave)){
            gameOver=true;
        }
    }
}


void Minijuego::update() {

    for (int i = 0; i < uAst; i++) {
        campoAsteroides[i].mover();
        campoAsteroides[i].rotar();
        campoAsteroides[i].choque_borde();
    }

    for (int i = 0; i < uDisp; i++) {
        disparos[i].mover();
    }

    detectarMisiles_bordes();
    detectarColisiones_Asteroides();
    colision_misiles_Asteroides();
    ganar();
    detectarColisionNave();
    
}

void Minijuego::ganar(){
    if(uAst <=0){
        campeon=true;
    }
}

void Minijuego::reiniciarJuego(){

    gameOver = false;
    campeon=false;
    
    liberarMemoria();
    generarJuego();
}

Minijuego::~Minijuego(){
    liberarMemoria();    
}

