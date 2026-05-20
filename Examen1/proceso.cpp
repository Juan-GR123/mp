/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   proceso.cpp
 * Author: juan
 *
 * Created on 5 de mayo de 2026, 19:34
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "proceso.h"

using namespace std;

/*
 * 
 */

/*
 1. una función palindromo que recibe un string s y devuelve true si s es un palíndromo. Si no
lo es, devuelve false. El procesamiento debe hacerlo utilizando punteros.
 */
bool palindromo(const string &s) {
    const char *inicio = s.c_str(); // convierte el string s en un array de char y se pone en su primera posicion
    const char *fin = inicio + s.length() - 1; // se pone en la ultima letra del string exceptuando el terminador \0

    bool espalindromo = true;
    
    while (inicio < fin) {
        if (*inicio != *fin)
            espalindromo = false;
        inicio++;
        fin--;
    }
    
    // se va avanzando y retrocediendo en cada posicion ya que se tiene que leer igual por derecha que por izquierda
    
    return espalindromo;
}


//otra forma
 /*bool palindromo(string &s) {
    string otro = "";

    for (int i = s.length() - 1; i >= 0; i--) {
        otro += s[i];
    }

    return s == otro;
}
*/

/*
 Implementar una función combinar que, dado un vector A de strings y su tamaño n,
construya y devuelva un vector B (y su tamaño) con todas las combinaciones de strings
string s3 = s1 + s2, con s1=A[i], s2=A[j] (∀ 𝑖 𝑗) tales que:
palindromo(s1) == palindromo (s2) == false y palindromo(s3) == true.
 */
string* combinar(string *A, int nA, int &nB) {
    nB = 0;
    string *B = new string[nB];

    // Contar
    for (int i = 0; i < nA-1; i++) {
        if(!palindromo(A[i])){
            for (int j = i + 1; j < nA; j++) {
                if (!palindromo(A[j])) {
                    string s3 = A[i] + A[j];
                    if (palindromo(s3)){
                        nB++;
                        redimensionar(B, nB);
                        B[nB-1] = s3;
                    }
                }
            }
        }
        
    }
    
    return B;
}

/*
3. Implementar una función maxMin que, dado un vector de strings X y su tamaño n
devuelva dos punteros a las cadenas de mayor y menor longitud, respectivamente. 
*/
void Maxmin(string* &A, int nA, string *&max, string *&min){
    max= &A[0];
    min= &A[0];
    
    for(int i=0; i<nA; i++){
        if(A[i].length() > max->length()){
            max = &A[i];
        }
        
        if(A[i].length() < min->length()){
            min= &A[i];
        }
    }
}


void redimensionar(string* &A, int nA){
     string* aux = new string[nA];
     
      if (A != nullptr) {
        for(int i=0; i<nA-1 ; i++){
             aux[i] = A[i]; 
        }
      }
     
     delete[] A;
     
     A = aux;
}


