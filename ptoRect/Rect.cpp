/*
 * File:   Rect.cpp
 * Author: David A. Pelta - Metodologías de la Programación
 *
  */

#include <iostream>

#include "Rect.h"
#include "Punto2D.h"
#include <cmath>

std::string toString(const Rect & r1) {
    std::string rta = "";
    rta = "[" + toString(r1.ul) + "," + toString(r1.dr) + "]";
    return rta;
}

float area(const Rect & r1) {
 
    float base = fabs(r1.ul.x - r1.dr.x);
    float altura = fabs(r1.ul.y - r1.dr.y);
    return base * altura / 2;
}

float perimetro(const Rect & r1) {
    float base = fabs(r1.ul.x - r1.dr.x);
    float altura = fabs(r1.ul.y - r1.dr.y);
    return 2 * (base + altura);

}

bool esMayor(const Rect & r1, const Rect & r2) {
    return area(r1) > area(r2);
}

bool estaDentro(const Rect & r1, const Punto2D & p) {
    bool enX = p.x >= r1.ul.x && p.x <= r1.dr.x;
    bool enY = p.y <= r1.ul.y && p.y >= r1.dr.y;
    return enX && enY;
}
