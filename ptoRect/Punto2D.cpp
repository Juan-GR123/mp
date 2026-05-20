/* 
 * File:   Punto2D.cpp
* Author: David A. Pelta - Metodologías de la Programación
 * 
 * Created on 12 de diciembre de 2025, 13:13
 */

#include <iostream>
#include <string>
#include <cmath>
#include "Punto2D.h"


std::string toString(const Punto2D & p){
    std::string rta = "";
    rta = "(" + std::to_string(p.x) + "," + std::to_string(p.y) + ")";
    return rta;
    
}

float distancia(const Punto2D & p1, const Punto2D & p2){
    float xx = (p1.x - p2.x) * (p1.x - p2.x);
    float yy = (p1.y - p2.y) * (p1.y - p2.y);
    
    return sqrt(xx + yy);
}

void puntoMedio(const Punto2D & p1, const Punto2D & p2, Punto2D & rta){
    rta.x = (p1.x + p2.x) / 2;
    rta.y = (p1.y + p2.y) / 2;
}