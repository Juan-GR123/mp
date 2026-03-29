#include "diccionario.h"

/*
1) las funciones donde aparece *** no deben utilizar el array datos, 

2) puede suponer que todas las palabras estan en mayusculas, 

3) las inserciones/borrados se realizan haciendo desplazamientos a derecha/izquierda. Recuerde actualizar el valor util,


y 4) pueden anadir todas las funciones auxiliares que crea conveniente (decida si deben incluirse o no en la parte publica 
del modulo).

*/

void crearDiccionario(Diccionario &dic){
    dic.cap = n_datos; // Para el array datos se reservaran´ n datos = N INDICE×2 componentes
    dic.util = N_INDICE;
    dic.datos = new string[dic.cap]; //reserva espacio para los strings del diccionario.
    dic.indice = new string*[dic.util]; //reserva espacio para los punteros que apuntarán a esos strings.

    for (int i = 0; i < dic.util; i++)
    {
        dic.datos[i] = string(1, 'A' + i); // convertir char a string ya que utilizamos las posiciones de ascii
        dic.indice[i] = &dic.datos[i];     // puntero al elemento
    }

    // posición extra al final del array indice
    dic.indice['Z'-'A' + 1] = &dic.datos[dic.util]; //la posicion donde esta z mas 1 mas para llegar al final del array
}

/*
mostrarPalabras: recibe un dato de tipo Diccionario y una letra inicial y 
muestra todas las palabras del diccionario que comienzan con inicial. ***
*/

void mostrarPalabras(Diccionario &dic, char letra){

    Diccionario aux;

    int inicio = dic.indice[letra - 'A'] - dic.datos; 
    int final   = dic.indice[letra - 'A' + 1] - dic.datos;
    int n_letras = final - inicio; 

    //dic.indice[letra - 'A'] apunta a algún elemento de datos
    //dic.datos apunta al primer elemento de datos
    //  int n_letras = final - inicio; te da el numero de elementos de diferencia entre una letra y otra

    aux.cap = n_letras;
    aux.util = n_letras;
    aux.datos = new string[aux.cap];
    aux.indice = new string*[aux.util];

    for (int i = 0; i < n_letras; i++) {

        aux.datos[i] = dic.datos[inicio + i];
        aux.indice[i] = &aux.datos[i];

    }

    cout << "Las palabras que empiezan por " << letra << " son: " << endl;

    for (int i = 0; i < aux.util; i++)
    {
       cout << *aux.indice[i] << " " << endl;
    }
    

    delete[] aux.datos;
    delete[] aux.indice;

    aux.util = 0;
    aux.cap = 0;


}

/*
mostrarDiccionario: utilizando la funcion anterior, muestra todas las palabras del diccionario
*/

void mostrarDiccionario(Diccionario &dic){ //como utilizo la funcion anterior aqui?
    Diccionario mostrar;

    mostrar.cap = dic.cap;
    mostrar.util = dic.util;
    mostrar.datos = new string[mostrar.cap];
    mostrar.indice = new string*[mostrar.util];

    cout << "Las palabras del array son: " << endl;

    for (int i = 0; i < mostrar.util; i++)
    {
        mostrar.datos[i] = dic.datos[i];
        mostrar.indice[i] = &mostrar.datos[i];
        cout << *mostrar.indice[i] << ", ";
    }

    cout << endl;

    delete[] mostrar.datos;
    delete[] mostrar.indice;

    mostrar.util = 0;
    mostrar.cap = 0;

}

/*
cuentaPalabras: recibe un dato de tipo Diccionario y devuelve la cantidad de palabras que empiezan con una letra dada. ***
*/

int cuentaPalabras(Diccionario &dic, char letra){ //Entonces pongo esta funcion en mostrarPalabras?
    int inicio = dic.indice[letra - 'A'] - dic.datos; 
    int final   = dic.indice[letra - 'A' + 1] - dic.datos;
    int n_letras = final - inicio; 

    return n_letras;


    //dic.indice[letra - 'A'] apunta a algún elemento de datos
    //dic.datos apunta al primer elemento de datos
    //  int n_letras = final - inicio; te da el numero de elementos de diferencia entre una letra y otra
}

/*
existe: recibe un dato de tipo Diccionario y un string pal comprueba si la palabra pal existe en el diccionario. Devuelve true o
false. ***
*/

