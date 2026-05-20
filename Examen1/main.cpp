/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
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
 para los array de string tenemos:
 * string.length() para la longitud
 * string.at() para saber la posición
 * 
 */
/*
 * 
 */
int main(int argc, char** argv) {
    string temp;
    int nA = 0;
    int nB=0;
    string* A = new string[nA];
    string* B = new string[nB];

    //Contar cuántos strings hay
    while (cin >> temp && temp != "FIN") {
        nA++;
        redimensionar(A,nA);
        A[nA - 1] = temp;
        
    }

    //Mostrar A
    cout << "Array A:" << endl;
    for (int i = 0; i < nA; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    //Combinar
 
    B = combinar(A, nA, nB);

    //Mostrar B
    cout << "\nArray B:" << endl;
    for (int i = 0; i < nB; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    //MaxMin sobre A
    string *maxA, *minA;
    Maxmin(A, nA, maxA, minA);

    cout << "\nMaxMin sobre A:" << endl;
    cout << "MAX " << *maxA << " (" << maxA->length() << ") -- MIN "
         << *minA << " (" << minA->length() << ")" << endl;

    //MaxMin sobre B
    if (nB > 0) {
        string *maxB, *minB;
        Maxmin(B, nB, maxB, minB);

        cout << "\nMaxMin sobre B:" << endl;
        cout << "MAX " << *maxB << " (" << maxB->length() << ") -- MIN "
             << *minB << " (" << minB->length() << ")" << endl;
    }

    // Liberar memoria
    delete[] A;
    delete[] B;

    return 0;
    
    
}

