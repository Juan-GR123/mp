/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juan
 *
 * Created on 5 de mayo de 2026, 23:29
 */

#include <cstdlib>
#include "PoliReg.h"
#include <iostream>
#include <cmath>
#include "raylib.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    PoliReg prueba1;
    
    cout << prueba1.toString() << endl;
    
    PoliReg prueba2(prueba1);
    
    cout << prueba2.toString() << endl;
    
    prueba2.agregaVertice();
    
    cout << prueba2.toString() << endl;
    
    prueba2.eliminaVertice();
    
    cout << prueba2.toString() << endl;
    
    prueba2.expande(20.5);
     
    cout << prueba2.toString() << endl;
    
    prueba2.contrae(20.5);
    
    cout << prueba2.toString() << endl;
    
    cout << prueba2.perimetro() << endl;
    
    prueba2.rotar(1.5708);
    
    cout << prueba2.toString() << endl;
    
    cout << prueba2.colision(prueba1) <<endl;
    
    cout << prueba2.colision(prueba2) << endl;
    
    prueba2.mover(31,0); //la distancia entre los dos poligonos debe de ser mayor que 30 para que no se choquen
    
    cout << prueba2.toString() << endl; 
    
    cout << prueba2.colision(prueba1) <<endl;
    
    PoliReg p2(-3, Punto2D(), 100);
    
    cout << p2.toString() << endl;
    
    cout << (p2.getLados() == 3) << endl;
}

