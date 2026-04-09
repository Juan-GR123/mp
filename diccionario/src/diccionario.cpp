#include "diccionario.h"

/*
1) las funciones donde aparece *** no deben utilizar el array datos, 

2) puede suponer que todas las palabras estan en mayusculas, 

3) las inserciones/borrados se realizan haciendo desplazamientos a derecha/izquierda. Recuerde actualizar el valor util,


y 4) pueden anadir todas las funciones auxiliares que crea conveniente (decida si deben incluirse o no en la parte publica 
del modulo).

*/

void crearDiccionario(Diccionario &dic){

    borrarDiccionario(dic);

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
    dic.datos[dic.util] = "000";
    dic.indice['Z'-'A' + 1] = &dic.datos[dic.util]; //la posicion donde esta z mas 1 mas para llegar al final del array
}

/*borrarDiccionario: recibe un dato de tipo Diccionario y libera toda la memoria reservada.*/
void borrarDiccionario(Diccionario &dic){

    if(dic.datos != nullptr){
        delete[] dic.datos;
        delete[] dic.indice;
        dic.datos = nullptr;
        dic.indice = nullptr;
        dic.util = 0;
        dic.cap = 0;
    }

}

/*
mostrarPalabras: recibe un dato de tipo Diccionario y una letra inicial y 
muestra todas las palabras del diccionario que comienzan con inicial. ***
*/

void mostrarPalabras(Diccionario &dic, char letra){
    string* posI = dic.indice[letra - 'A'];//posicion de la letra
    string* posF = dic.indice[letra - 'A' + 1]; //posicion de la siguiente letra

    while( posI <= posF){
        cout << *posI; //muestra la siguiente palabra
        posI++;
    }
}

/*
mostrarDiccionario: utilizando la funcion anterior, muestra todas las palabras del diccionario***
*/

void mostrarDiccionario(Diccionario &dic){ //como utilizo la funcion anterior aqui?
    mostrarPalabras(dic, 'Z');
}

/*
cuentaPalabras: recibe un dato de tipo Diccionario y devuelve la cantidad de palabras que empiezan con una letra dada. ***
*/

int cuentaPalabras(Diccionario &dic, char letra){

}

/*
existe: recibe un dato de tipo Diccionario y un string pal comprueba si la palabra pal existe en el diccionario. Devuelve true o
false. ***
*/
bool existe(Diccionario &dic , string pal){

}