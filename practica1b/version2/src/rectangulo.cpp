#include "rectangulo.h"
#include <cmath>

Rectangulo::Rectangulo() : iz_sup(Punto()), dr_inf(Punto())
{
}

Rectangulo::Rectangulo(Punto piz, Punto pdr) : iz_sup(Punto(piz)), dr_inf(Punto(pdr))
{
}

Punto Rectangulo::getX() const
{
    return iz_sup;
}

Punto Rectangulo::getY() const
{
    return dr_inf;
}

void Rectangulo::setX(Punto px)
{
    iz_sup = px;
}

void Rectangulo::setY(Punto py)
{
    dr_inf = py;
}

// devuelve un string con el formato [(x1,y1),(x2,y2)]
string Rectangulo::toString() const
{
    string rta = "[" + iz_sup.toString() + "," + dr_inf.toString() + "]";
    return rta;
}

double Rectangulo::area() const
{
    double base = abs(dr_inf.getX() - iz_sup.getX());
    double altura = abs(iz_sup.getY() - dr_inf.getY());
    return base * altura; // formula de la base
}

double Rectangulo::perimetro() const
{
    double base = abs(dr_inf.getX() - iz_sup.getX());
    double altura = abs(iz_sup.getY() - dr_inf.getY());
    return 2 * (base + altura); // formula del perimetro
}

// Devuelve true si el área de r1 es mayor que la de r2
bool Rectangulo::esMayor(const Rectangulo &r2) const
{
    return area() > r2.area();
}

// Devuelve true si el punto p está dentro del rectángulo r
bool Rectangulo::estaDentro(const Punto &p) const
{
    double x = p.getX();
    double y = p.getY();

    return (x >= iz_sup.getX() && x <= dr_inf.getX() && y <= iz_sup.getY() && y >= dr_inf.getY());
}