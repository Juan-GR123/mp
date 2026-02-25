#include "rectangulo.h"
#include <cmath>

Rectangulo::Rectangulo() : ul(Punto()), dr(Punto()){

}

Rectangulo::Rectangulo(Punto pul, Punto pdr) : ul(Punto(pul)) , dr(Punto(pdr)){

}

Punto Rectangulo::getX() const{
    return ul;
}

Punto Rectangulo::getY() const{
    return dr;
}

void Rectangulo::setX(Punto px) {
    ul = px;
}

void Rectangulo::setY(Punto py) {
    dr = py;
}

// devuelve un string con el formato [(x1,y1),(x2,y2)]
string Rectangulo::toString() const {
    string rta = "[" + ul.toString() + "," + dr.toString() + "]";
    return rta;
}

double Rectangulo::area(const Rectangulo p1) const {
    double base = p1.dr.getX() - p1.ul.getX();
    double altura =p1.ul.getY() - p1.dr.getY();
    return base * altura;
}

double Rectangulo::perimetro(const Rectangulo p2) const {
    double base = p2.dr.getX() - p2.ul.getX();
    double altura = p2.ul.getY() - p2.dr.getY();
    return 2 * (base + altura);
}

// Devuelve true si el área de r1 es mayor que la de r2
bool Rectangulo::esMayor(const Rectangulo r1, const Rectangulo r2) const {
    return area(r1) > area(r2);
}

// Devuelve true si el punto p está dentro del rectángulo r
bool Rectangulo::estaDentro(const Rectangulo r, const Punto p) const {
    double x = p.getX();
    double y = p.getY();

    return (x >= r.ul.getX() && x <= r.dr.getX() && y <= r.ul.getY() && y >= r.dr.getY());
}