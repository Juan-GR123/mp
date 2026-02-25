/*
Modulo Rectangulo ´

toString: recibe un dato de tipo Rectangulo y devuelve un string
con formato [(x1,y1),(x2,y2)].

area: recibe un dato de tipo Rectangulo y devuelve su area. ´

perimetro: recibe un dato de tipo Rectangulo y devuelve su per´ımetro.

esMayor: recibe dos datos r1,r2 de tipo Rectangulo y devuelve
verdadero si el area de r1 es mayor que el de r2. Devuelve falso en ´
caso contrario.

estaDentro: recibe un dato r de tipo Rectangulo y un dato p de
tipo Punto2D. Devuelve verdadero si p ”esta dentro” del rect ´ angulo ´
r y falso en caso contrario.
 */

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "punto2d.h"
#include <string>
using namespace std;

class Rectangulo{
private:
    Punto ul;
    Punto dr;
public:
    Rectangulo();
    Rectangulo(Punto pul, Punto pdr);
    Punto getX() const;
    Punto getY() const;
    void setX(Punto newXValue);
    void setY(Punto newYValue);
    string toString() const; // recibe un dato de tipo Rectangulo y devuelve un string con formato [(x1,y1),(x2,y2)].
    double area(const Rectangulo p1) const; //Recibe un dato de tipo Rectangulo y devuelve su area
    double perimetro(const Rectangulo p2) const; //recibe un dato de tipo Rectangulo y devuelve su per´ımetro.
    bool esMayor(const Rectangulo r1, const Rectangulo r2)const; //recibe dos datos r1,r2 de tipo Rectangulo y devuelve verdadero si el area de r1 es mayor que el de r2. Devuelve falso en caso contrario.
    bool estaDentro(const Rectangulo r,const Punto p) const;//estaDentro: recibe un dato r de tipo Rectangulo y un dato p detipo Punto2D. Devuelve verdadero si p ”esta dentro” del rect ´ angulo ´r y falso en caso contrario.
};
#endif /* RECTANGULO_H */