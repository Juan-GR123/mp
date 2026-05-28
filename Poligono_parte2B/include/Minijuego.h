/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Minijuego.h
 * Author: juan
 *
 * Created on 28 de mayo de 2026, 16:26
 */

#ifndef MINIJUEGO_H
#define MINIJUEGO_H

#include "Asteroide.h"
#include <iostream>
#include <cmath>

using namespace std;

class Minijuego{
    private:
        Asteroide *campoAsteroides;
        int uAst = 0;
        Asteroide *disparos ;
        int uDisp = 0;
        Asteroide nave ;
        void liberarMemoria();
    public:
        Minijuego();
        Minijuego(const Asteroide *campo, int nCampo,const Asteroide *disp, int nDisp,const Asteroide &nav);
        void disparar();
        void moverYrotar();
        void update();
        void detectarColisiones_Asteroides();
        void detectarColisiones_bordes();
        void pintar();
        void detectarMisiles_bordes();
        Asteroide getCampo(int i) const;
        int getuAst() const;
        int getuDisp() const;
        Asteroide getNave() const;
        Asteroide getDisparos(int i) const;
        ~Minijuego();
};


#endif /* MINIJUEGO_H */

