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

   for(string* p = posI; p < posF; p++){
        cout << *p << " ";
    }
    cout << endl;
}

/*
mostrarDiccionario: utilizando la funcion anterior, muestra todas las palabras del diccionario***
*/

void mostrarDiccionario(Diccionario &dic){
    for(char c = 'A'; c <= 'Z'; c++){
        mostrarPalabras(dic, c);
    }
}

/*
cuentaPalabras:  recibe un dato de tipo Diccionario y una letra inicial y devuelve la cantidad 
de palabras que empiezan con dicha letra. Los valores individuales “A”, “B”, “C” cuentan como palabras. ***
*/

int cuentaPalabras(Diccionario &dic, char letra){
    string* posI = dic.indice[letra - 'A'];//posicion de la letra
    string* posF = dic.indice[letra - 'A' + 1]; //posicion de la siguiente letra
    int contador = 0;

    while( posI < posF){
        contador++;
        posI++;
    }

    return contador;
}

/*
existe: recibe un dato de tipo Diccionario y un string pal comprueba si la palabra pal existe en el diccionario. 
Devuelve true o false. ***
*/
bool existe(Diccionario &dic , string pal){
    char inicial = pal[0];
    bool existe_pal= false;

    string* posI = dic.indice[inicial - 'A'];
    string* posF = dic.indice[inicial - 'A' + 1];

    while (posI < posF) {
        if (*posI == pal) {
            existe_pal=true;
        }
        posI++;
    }

    return existe_pal;
}

/*
agregaPalabra: recibe un dato de tipo Diccionario y un string pal. 
Si la palabra pal a agregar ya existe, no hace nada. 

En otro caso, si no hay espacio en el array datos debe redimensionarlo
primero en TAM = 5 unidades. Posteriormente la palabra debe insertarse en datos. Puede agregarla al final de las palabras que
comienzan con la letra pal[0] (el primer caracter de ´ pal), o de forma ordenada.

Tenga en cuenta que cada insercion produce un desplazamiento de 
valores en el array datos. Por tanto, es necesario actualizar tambien el indice.

Recuerde que si redimensiona, todos los valores de indice deben ser actualizados.

*/

void agregaPalabra(Diccionario &dic, string pal){

    // 1. comprobar si existe
    if (existe(dic, pal)){
        cout << "La palabra que quieres agregar al diccionario ya existe " << endl;
    }else{


    }
        

    
}

/*
borraPalabra: recibe un dato de tipo Diccionario y un string pal. 
Elimina la palabra pal si existe en el diccionario. Cada borrado
produce un desplazamiento de valores en el array datos.

Por tanto, es necesario actualizar tambien el ´ indice. 
Si luego del borrado, el espacio libre en datos es mayor que 2 * TAM, 
entonces debe reducir el tamano del array en ˜ 2 * TAM unidades. No olvide actualizar el array indice.

*/

void borraPalabra(Diccionario &dic, string pal){

    if(!existe(dic, pal)){
        cout << "La palabra que intentas eliminar del diccionario no existe" << endl;
    }else{
      
    }
}

/*
extraePalabras: recibe un dato de tipo Diccionario y una letra inicial y devuelve un puntero a un array dinamico de strings 
conteniendo todas las palabras que empiezan con inicial, y su tamaño
***
*/

void extraePalabras(Diccionario &dic, char letra, string* &resultado, int &tam){
    tam = cuentaPalabras(dic, letra);

    string* posI = dic.indice[letra - 'A'];//posicion de la letra
    string* posF = dic.indice[letra - 'A' + 1]; //posicion de la siguiente letra

    // reservar array dinámico
    resultado = new string[tam];
    
    // copiar palabras
    int contador = 0;
    for (string* i = posI; i < posF; i++) {
        resultado[contador] = *i;// se guardan los string en el nuevo array dinamico
        contador++;
    }

}

/*
copiarDiccionario: recibe dos datos de tipo Diccionario D1,
D2 y realiza una copia profunda de D1 en D2. Recuerde que D2
puede tener datos, en cuyo caso debe primero liberar la memoria
asignada.
*/


void copiarDiccionario(Diccionario &dic1, Diccionario &dic2){
    borrarDiccionario(dic2);

    dic2.cap=dic1.cap;
    dic2.util = dic2.util;

    dic2.datos = new string[dic2.cap];
    dic2.indice = new string*[dic1.util];


    for (int i = 0; i < dic1.util; i++)
    {
        dic2.datos[i] = dic1.datos[i];
        dic2.indice[i] = &dic2.datos[i];
    }
    
    dic2.datos[dic1.util] = "000";
    dic2.indice[dic1.util] = &dic2.datos[dic1.util];

    
}