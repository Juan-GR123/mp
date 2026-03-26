#include <iostream>
#include <cstring>
#include "memoria.h"

using namespace std;


const int TAM = 3;        // capacidad inicial
const int TAM_BLOQUE = 5; // para tipo 2

int main(){
    string* p= new string[TAM];
    int util = 0;                // elementos usados
    int cap = TAM;               // capacidad total
    string palabra;

    cout << "Introduce palabras (FIN para terminar):" << endl;

    cin >> palabra;

    if(palabra != "FIN"){

        if(util == cap){
            int tipo;
            cout << "No hay espacio. Tipo de redimension:" << endl;
            cout << "1: +1 posicion" << endl;
            cout << "2: +TAM_BLOQUE posiciones" << endl;
            cout << "3: duplicar capacidad" << endl;
            cout << "Opcion: ";
            cin >> tipo;

            Redim(p, util, tipo, cap); 
        }


        p[util] = palabra;
        util++;

        cin >> palabra;
    }

    // Mostrar contenido
    cout << "Contenido del array: " << endl;
    for (int i = 0; i < util; i++) {
        cout << p[i] << endl;
    }

    // Liberar memoria
    delete[] p;

    return 0;
}