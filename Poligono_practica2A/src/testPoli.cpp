/*
 * File:   test.cpp
 * Author: David A. Pelta
 * Fichero de pruebas para la clase PoliReg y Punto2D
 * Atiende las explicaciones en clase para la descripción de cada test.
 *
 * Constantes utilizadas een PoliReg
 * const float PoliReg::MAX_RAD = 600.0;
 * const float PoliReg::MIN_RAD = 15.0;
 * const int PoliReg::MAX_VERT = 30;
 * const int PoliReg::MIN_VERT = 3;
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "PoliReg.h"
#include "Punto2D.h"
#include <cstring>
#include <ctime>
#include <random>

using namespace std;

TEST_CASE("Pruebas Basicas") {
  SUBCASE("\nConstructores") {

    cout << "\nPRUEBA Constructor-Destructor " << endl;
    PoliReg p0;
    PoliReg p1(5, Punto2D(), 10);
    PoliReg p2(-3, Punto2D(), 100);
    CHECK(p2.getLados() == 3);

    PoliReg p3(4, Punto2D(), 10000);
    CHECK(p3.getRadio() < 10000);

    PoliReg p4(p3);
    CHECK(p4.getRadio() == p3.getRadio());
    CHECK(p4.getLados() == p3.getLados());
    CHECK(p4.perimetro() == p3.perimetro());
  }

  SUBCASE("AGREGAR VERTICES") {
    cout << "\nPRUEBA Agrega vertices hasta ajustar a circunferencia " << endl;
    Punto2D centro(400, 400);
    int radio = 25;

    PoliReg pol(3, centro, radio); 
    double peri = pol.perimetro();
    double longitud =  2 * M_PI * radio; // la longitud de la circunferencia que contiene al poligono
    int pasos = 0;
    double delta = longitud - peri;
    cout << "\nDatos iniciales " << endl;
    cout << "Lados PoliReg:" << pol.getLados() << " Perim: " << peri
           << " Long. Circ: " << longitud << " Dif.: " << delta << endl;
    cout << "---------------------------------\n";

    while (delta > 2.0) {
      pol.agregaVertice();
      peri = pol.perimetro();
      delta = longitud - peri;
      cout << "Lados PoliReg:" << pol.getLados() << " Perim: " << peri
           << " Long. Circ: " << longitud << " Dif.: " << delta << endl;
    }

    CHECK(pol.getLados() == 12);
  }

  SUBCASE("\nPRUEBA: Contrae-Expande poligono ") {
    cout << "\nPRUEBA: Contrae-Expande poligono " << endl;
    int radio = 100;
    Punto2D centro(400, 400);
    PoliReg pol3(3, centro, radio);
    double perimRef = pol3.perimetro();

   cout << "\nDatos iniciales\n";
   cout << "Radio: " << pol3.getRadio() << " Perimetro " << pol3.perimetro() << endl;
  cout << "-----------------------------------------\n";


    for (int i = 0; i < 10; i++) {
      pol3.expande(10);
      cout << "Radio: " << pol3.getRadio() << " Perimetro " << pol3.perimetro()
           << endl;
    }

    for (int i = 0; i < 10; i++) {
      pol3.contrae(10);
      cout << "Radio: " << pol3.getRadio() << " Perimetro " << pol3.perimetro()
           << endl;
    }

    CHECK(pol3.getRadio() == radio);
    CHECK(pol3.perimetro() == perimRef);
  }

  SUBCASE("PRUEBA Expande poligonos") {

    cout << "\nPRUEBA Expande poligonos mientras no colisionen " << endl;
    Punto2D c1(100, 100);
    PoliReg pol1(5, c1, 15);
    Punto2D c2(300, 300);
    PoliReg pol2(5, c2, 30);
    int steps = 0;

    CHECK(!pol2.colision(pol2));
    cout << "\n\nDistancia entre centros " << c1.distancia(c2) << endl;
    while (!pol1.colision(pol2)) {
      pol1.expande(10);
      pol2.expande(10);
      cout << "Suma de radios: " << pol1.getRadio() << " + " << pol2.getRadio()
           << " = " << pol1.getRadio() + pol2.getRadio() << endl;
      steps++;
    }

    // cout << steps << endl;
    CHECK(steps == 12);
  }

  SUBCASE("Agrega/Elimina vertices") {
    Punto2D centro(400, 400);
    int nVerts1 = 25;
    int nVerts2 = 3;
    int base = 22;

    PoliReg p1(nVerts1, centro, 200);
    PoliReg p2(nVerts2, centro, 300);
    int pasos = 0;

    cout << "\nPRUEBA agrega - elimina vertices " << endl;

    while (p1.getLados() >= p2.getLados()) {
      p2.agregaVertice();
      p1.eliminaVertice();
      cout << "Lados Polig. 1: " << p1.getLados()
           << " - Lados Polig. 2: " << p2.getLados() << endl;
      pasos++;
      CHECK((p1.getLados() - p2.getLados()) == (base - pasos * 2));
    }

    cout << pasos << endl;
    CHECK(p1.getLados() < p2.getLados());
    CHECK(pasos == 12);
  }

  SUBCASE("Rotacion") {
    cout << "\nPrueba Rotacion" << endl;
    // crear punto y comprobar si al rotarlo, coincide con el del poligono
    Punto2D centro(20, 20);
    Punto2D ref(35, 20);
    PoliReg p(3, centro, 15);


    cout << "Punto 0 del PoliReg " << p.getVertice(0).toString() << " - Ref: " << ref.toString() << endl;
    // el primer punto del poligono estará en (30,20);
    float rad = 3;
    for (int i = 0; i < 10; i++) {
      p.rotar(rad);
      ref.rotar(centro, rad);
      cout << "Punto 0 del PoliReg " << p.getVertice(0).toString() << " - Ref: " << ref.toString() << endl;
      CHECK(fabs(p.getVertice(0).getX() - ref.getX()) < 0.0001);
      CHECK(fabs(p.getVertice(0).getY() - ref.getY()) < 0.0001);
    }
  }
}

void aplicarMetodo(PoliReg & poli, int code){
switch (code){
  case 1: {poli.agregaVertice(); break;}
  case 2: {poli.eliminaVertice(); break;}
  case 3: {poli.expande(10); break;}
  case 4: {poli.contrae(6); break;}
  case 5: {poli.rotar(4); break;}
  case 6: {poli.mover(2.3f,-2.0f); break;}
}
}


TEST_CASE("Pruebas Conjuntas") {
  SUBCASE("\nVarias pruebas") {
    srand(time(nullptr));
    const int MAX = 10;
    const int OPERS = 6;
    const int VECES = 200;
    PoliReg v[MAX];
    // para cada polígono, aplico una operación elegida al azar
    int opc = rand() % OPERS;
    for(int i = 0; i < VECES; i++){
      for(int poli = 0; poli < MAX; poli++){
        opc = rand() % OPERS;
        aplicarMetodo(v[poli], opc);
      }
  }

  cout << "\nPOLIGONOS FINALES" << endl;
  for(int i = 0; i <  MAX; i++)
    cout << v[i].toString() << endl;
  }
}




