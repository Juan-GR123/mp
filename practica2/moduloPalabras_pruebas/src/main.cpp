/*
 * File:   main.cpp
 * Author: David A. Pelta
 *
 * Created on 10 de marzo de 2023
 */

/*
NOMBRE Y APELLIDOS: Juan García Rosales
DNI:
GRUPO DE PRÁCTICAS: Miércoles
*/

#include <iostream>
#include "palabras.h"
#include <cstring>
using namespace std;

const int FIL = 6;
const int COL = 80;

void testBasico(const char frase[])
{
    cout << "\nLA FRASE LEIDA ES: " << frase << endl;
    int n = longitud(frase);
    int pals = cuentaPalabras(frase);
    cout << "Tiene " << n << " caracteres y " << pals << " palabras " << endl;
}

void testPalabras(const char frase[])
{
    char palabra[MAX_SIZE];

    cout << "\nDESCOMPOSICION EN PALABRAS nro -> palabra (long.)" << endl;
    int nro = 1;
    extraePalabra(frase, nro, palabra);
    while (longitud(palabra) > 0)
    {
        cout << nro << " -> " << palabra << " (" << longitud(palabra) << ")\n";
        nro++;
        extraePalabra(frase, nro, palabra);
    }
}

void testInvierte(const char frase[])
{

    char reves[MAX_SIZE];
    cout << "\nFRASE INVERSA " << endl;
    delReves(frase, reves);
    cout << "Frase Original: " << frase;
    cout << "\nFrase al Reves: " << reves << endl;
}

//
// void mostrar(const char pag[][COL]){
// for(int i = 0; i < FIL; i++)
//   cout << pag[i] << endl;
//
//}

int main()
{

    char frase[MAX_SIZE];

    cout << "Ingrese la frase. <ENTER> para terminar: ";
    cin.getline(frase, MAX_SIZE);
    testBasico(frase);
    testPalabras(frase);
    testInvierte(frase);

    // el codigo siguiente permite leer 6 frases utilizando redirección de entrada
    // se puede utilizar para probar la función "justifica"
    // y sirve para ilustrar el manejo de cada fila de una matriz como un array

    /*
    char m[FIL][COL];

    for(int i = 0; i < FIL; i++)
        cin.getline(m[i], COL);

    mostrar(m);

    for(int i = 0; i < FIL; i++)
        justifica(m[i],COL);

    mostrar(m);
     */
    return (0);
}
