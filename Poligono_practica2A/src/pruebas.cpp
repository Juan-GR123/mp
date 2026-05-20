/*
 PROGRAMA DE PRUEBAS BASICAS PARA LA CLASE PoliReg
 Metodologías de la Programación
 Grupo C

 Atiende a las explicaciones del código dadas en clase de prácticas.
 
 */

#include <iostream>
#include "Punto2D.h"
#include "PoliReg.h"
#include <cassert>
#include <cstdlib>

using namespace std;

void test1() {
    cout << "Prueba operator<<" << endl;
    PoliReg a1;
    PoliReg a2(4, Punto2D(50, 50), 20);

    cout << "Salida 1" << endl;
    cout << a1 << endl;
    cout << a2 << endl;

    cout << "Salida 2" << endl;
    cout << a1 << a2 << endl;
}

void test2() {
    cout << "Prueba operator>>" << endl;

    PoliReg a1(30, Punto2D(), 50);
    cin >> a1;
    cout << a1 << endl;
    cin >> a1;
    cout << a1 << endl;

}

void test3() {
    cout << "Prueba operator>>" << endl;

    PoliReg a1(30, Punto2D(), 50);
    PoliReg a2;

    cin >> a1 >> a2;
    cout << a1 << endl;
    cout << a2 << endl;
}

void test4() {
    cout << "Prueba operator==" << endl;

    PoliReg a1(4, Punto2D(), 20);
    PoliReg a2;

    assert(!(a1 == a2));

    a2 = a1;

    assert(a1 == a2);

    a2.expande(20);
    assert(!(a1 == a2));

    PoliReg a3(4, Punto2D(), 20);
    assert(a3 == a3);


    //cout << "Prueba pasada" << endl;
}

void test5() {
    cout << "Prueba operator<" << endl;

    PoliReg a1(4, Punto2D(), 100);
    PoliReg a2(a1);

    cout << "!(a1 < a2)" << endl;
    cout << "a1: " << a1.perimetro() << ", " << "a2: " << a2.perimetro() << endl;
    assert(!(a1 < a2));
    a2.expande(10);


    cout << "(a1 < a2)" << endl;
    cout << "a1: " << a1.perimetro() << ", " << "a2: " << a2.perimetro() << endl;
    assert(a1 < a2);

    a2.contrae(11);

    cout << "(a1 > a2)" << endl;
    cout << "a1: " << a1.perimetro() << ", " << "a2: " << a2.perimetro() << endl;
    assert(a2 < a1);

}

void swap(PoliReg & p1, PoliReg & p2) {
    PoliReg aux(p1);
    p1 = p2;
    p2 = aux;
}

void test6() {
    const int MAX = 5;
    PoliReg v[MAX];

    for (int i = 0; i < MAX; i++)
        cin >> v[i];


    for (int i = 0; i < MAX; i++)
        cout << v[i] << endl;

    swap(v[0], v[MAX - 1]);
    swap(v[1], v[MAX - 2]);

    for (int i = 0; i < MAX; i++)
        cout << v[i] << endl;

}

void ordenar() {

    // para generar un nro x entre [min, max] utiliza x = random()%(max-min) + min  
    
    //1. Crear un array din ´amico v de 10 polígonos.
    PoliReg* v = new PoliReg[10];

    //formula general: rand() % (max - min + 1) + min
    //2. Asignar a cada elemento de v un nuevo polígono generado al azar,
    //donde el número de lados n ∈ [5, 10], el centro se genera como un
    //punto2D al azar y el radio r ∈ [20, 150].
    for (int i = 0; i < 10; i++) {
        int n = rand() % (10 - 5 + 1) + 5;
        float r = rand() % (150 - 20 + 1) + 20;

        float x = rand() % (100 - (-100) + 1) - 100;// estaria relativamente dentro de la escala [-100,100]
        float y = rand() % (100 - (-100) + 1) - 100;

        Punto2D c(x, y);

        v[i] = PoliReg(n, c, r);
    }
    
    //    3. Muestre el per´ımetro de cada pol´ıgono del array.
    cout << "Antes de ordenar: " <<endl;
    for (int i = 0; i < 10; i++) {
        cout << v[i].perimetro() << endl;
    }
    
    //4. ordenar los polígonos en función de su perímetro.
    for(int i=0; i < 9; i++){ // el numero de pasadas que se hace al array
        for(int j=0; j< 9; j++){ //los elementos que se comparan los unos con los otros
            if (v[j+1] < v[j]) {
                PoliReg cambiar = v[j];
                v[j] = v[j+1];
                v[j+1] = cambiar; // se pone el mayor en la siguiente posicion y en la anterior el menor
            }
        }
    }
    
    //   5. Muestre el perimetro de cada pol´ıgono del array.
    cout << "Despues de ordenar: " <<endl;
    
    for (int i = 0; i < 10; i++) {
        cout << v[i].perimetro() << endl;
    }
}

int main(int argc, char ** argv) {

    srand(time(NULL));
        
    if (argc > 1) {
        int opcion = atoi(argv[1]);
      


        // para las pruebas 2 y 3 utiliza el fichero datos.txt para la
        // redireccion de la entrada

        // para la prueba 6, utiliza el fichero datos5polis.txt
        switch (opcion) {
            case 1: {
                test1();
                break;
            }
            case 2: {
                test2();
                break;
            }
            case 3: {
                test3();
                break;
            }
            case 4: {
                test4();
                break;
            }
            case 5: {
                test5();
                break;
            }
            case 6: {
                test6();
                break;
            }
            case 7: {
                ordenar();
                break;
            }
            default: {
                cout << "Número de prueba inválido" << endl;
                break;
            }
        }
    } else
        cout << "Debes indicar un número de prueba a ejecutar (entre 1 y 7)" << endl;


    return 0;
}
