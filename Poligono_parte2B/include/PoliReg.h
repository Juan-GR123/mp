/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PoliReg.h
 * Author: juan
 *
 * Created on 5 de mayo de 2026, 23:30
 */

#ifndef _POLIREG_H
#define _POLIREG_H

#include "Punto2D.h"
#include <iostream>
#include <cmath>

using namespace std;

class PoliReg{
private :
    static const int MAX_VERT; //lims para nro de vertices
    static const int MIN_VERT ;
    static const float MAX_RADIO; //lims para el radio
    static const float MIN_RADIO ;
    static const double PI;

    Punto2D * vertices; //un array de puntos para los vertices
    int N;//nro de vertices del poligono
    Punto2D centro; //el centro de la circunferencia
    float radio; //y su radio
    
    void reservaMemoria(int tam);
    void liberaMemoria();        
    void generaVertices();
    void copiar(const PoliReg &otro);
    
public :
    
PoliReg();


PoliReg(int nVert, const Punto2D & centro2, float r);

Punto2D getVertice(int i) const;

Punto2D getCentro() const;

int getLados() const;

float getRadio() const;

PoliReg(const PoliReg & otro);

void agregaVertice();

void eliminaVertice();

void expande(float delta);

void contrae(float delta);

double perimetro() const;

void rotar(float rads);

bool colision(const PoliReg & otro);

void mover(float dx, float dy);

PoliReg& operator =(const PoliReg &rhs);//esto tiene que ir fuera de la clase???

friend ostream& operator<<(ostream &flujo, const PoliReg &otro);

friend istream& operator>>(istream &flujo, PoliReg &otro);

bool operator ==(const PoliReg &rhs);

bool operator <(const PoliReg &rhs);

~PoliReg();

string toString() const;
};



#endif /* POLIREG_H */


