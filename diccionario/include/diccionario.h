#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <string>

using namespace std;

struct Diccionario{
    string *datos; //reserva espacio para los strings del diccionario.
    int cap;      // capacidad del array datos
    int util;     // nro elementos almacenados en datos
    string** indice; //reserva espacio para los punteros que apuntarán a esos strings.
};


const int N_INDICE = 'Z' - 'A' + 1; // 27 letras + 1
const int n_datos = N_INDICE * 2;

void crearDiccionario(Diccionario &dic);

void mostrarPalabras(Diccionario &dic, char letra);

void mostrarDiccionario(Diccionario &dic);

int cuentaPalabras(Diccionario &dic, char letra);

#endif