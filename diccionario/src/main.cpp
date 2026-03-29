#include <iostream>
#include <cstring>
#include <string>
#include "diccionario.h"


using namespace std;

int main(){

    Diccionario datos;

    crearDiccionario(datos);

      // Mostrar
    for (int i = 0; i < datos.util; i++) {
        cout << *datos.indice[i] << ", ";
    }


    char letra;
    cout << "Para ver las palabras que del diccionario que empiezan por una letra introduce una: " << endl;
    cin >> letra;

    mostrarPalabras(datos, letra);

    mostrarDiccionario(datos);

    int palabras = cuentaPalabras(datos, letra); 
    cout << "El numero de palabras que empiezan por la letra " << letra << " es " << palabras << endl;

    // Liberar memoria
    delete[] datos.datos;
    delete[] datos.indice;

    datos.util = 0;
    datos.cap = 0;

}