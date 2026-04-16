#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <string>

using namespace std;

struct Diccionario{
    string *datos; //reserva espacio para los strings del diccionario.
    string** indice; //reserva espacio para los punteros que apuntarán a esos strings.
    int cap;      // cuántas posiciones hay reservadas en memoria
    int util;     // nro elementos almacenados en datos
};


const int N_INDICE = 'Z' - 'A' + 2; // 26 letras + 2
const int N_DATOS = N_INDICE * 2;

void crearDiccionario(Diccionario &dic);

void redimensionar(Diccionario &dic, int tipo);

void borrarDiccionario(Diccionario &dic);

void mostrarPalabras(Diccionario &dic, char letra);

void mostrarDiccionario(Diccionario &dic);

int cuentaPalabras(Diccionario &dic, char letra);

bool existe(Diccionario &dic , string pal);

void agregaPalabra(Diccionario &dic, string pal);

void borraPalabra(Diccionario &dic, string pal);

void copiarDiccionario(Diccionario &dic1, Diccionario &dic2);

string* extraePalabras(Diccionario &dic, char letra, int &tam);

#endif