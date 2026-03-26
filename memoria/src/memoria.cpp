
#include "memoria.h"



void Redim(string* & p, int util, int tipo, int & cap){

    int nuevo_cap;
    if(tipo == 1){

        nuevo_cap = cap + 1;
       
    }else if(tipo == 2){
        nuevo_cap = cap + TAM_BLOQUE;
    }else if(tipo == 3){
        nuevo_cap = cap*2;
    }

    string* aux = new string [nuevo_cap];
        
    for (int i = 0; i < util; i++){
            aux[i] = p[i];
    }
        
    delete[] p;

    // Apuntar al nuevo array
    p = aux;

    // Actualizar capacidad
    cap = nuevo_cap;


}