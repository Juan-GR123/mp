#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>

using namespace std;
const int TAM_BLOQUE = 5;
const int TAM = 3;        // capacidad inicial

void Redim(string* & p, int util, int tipo, int & cap);

#endif