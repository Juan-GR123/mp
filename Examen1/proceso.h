/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   proceso.h
 * Author: juan
 *
 * Created on 5 de mayo de 2026, 19:35
 */
#ifndef PROCESO_H
#define PROCESO_H

#include <iostream>
#include <string>


using namespace std;

bool palindromo(const string &s);

string* combinar(string* A,  int nA, int &nB);

void Maxmin(string* &A, int nA, string *&max, string *&min);

void redimensionar(string* &A, int nA);

#endif /* PROCESO_H */

