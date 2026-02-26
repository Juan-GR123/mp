#include <iostream>
#include <cmath>
#include <string>
#include "punto2d.h"
#include "rectangulo.h"

using namespace std;

int main()
{
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
    double xp, yp;

    cout << "introduzca datos para el primer rectangulo:\n";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "introduzca datos para el segundo rectangulo:\n";
    cin >> x3 >> y3 >> x4 >> y4;

    cout << "Dame un punto:\n";
    cin >> xp >> yp;

    // Crear puntos
    Punto p1(x1, y1);
    Punto p2(x2, y2);
    Punto p3(x3, y3);
    Punto p4(x4, y4);
    Punto p(xp, yp);

    // Crear rectángulos
    Rectangulo r1(p1, p2);
    Rectangulo r2(p3, p4);

    // Mostrar rectángulos
    cout << "Rectangulo 1: " << r1.toString() << endl;
    cout << "Rectangulo 2: " << r2.toString() << endl;

    // Área
    cout << "Area r1: " << r1.area() << endl;
    cout << "Area r2: " << r2.area() << endl;

    // Perímetro
    cout << "Perimetro r1: " << r1.perimetro() << endl;
    cout << "Perimetro r2: " << r2.perimetro() << endl;

    // Comparación
    if (r1.esMayor(r2))
        cout << "r1 es mayor que r2" << endl;
    else
        cout << "r1 NO es mayor que r2" << endl;

    // Punto dentro
    if (r1.estaDentro(r1, p))
        cout << "El punto esta dentro de r1" << endl;
    else
        cout << "El punto NO esta dentro de r1" << endl;

    return 0;
}