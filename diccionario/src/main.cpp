/*
Curso: Metodologias de la Programacion

Prof: David A. Pelta

Fichero simple de pruebas para el módulo diccionario

En lugar de colocar todo el código en la función main, se utilizan funciones 
diferentes para probar las funcionalidades del módulo Diccionario. 

*/


#include <iostream>
#include <string>
#include "diccionario.h"
using namespace std;

void cartel(string msg){
    cout << "\n\n**************************************" << endl;
    cout << msg << endl;
     cout << "**************************************" << endl;   
}

// ANALICE EL CÓDIGO DE CADA FUNCIÓN, INTENTANDO ENTENDER QUÉ ES LO QUE HACE.

void basico1(){
    cartel("crear/borrar llamadas consecutivas");
    Diccionario miDic = {nullptr, nullptr, 0,0};
    crearDiccionario(miDic);

    /*
    for (int i = 0; i < miDic.util; i++)
    {
        cout << miDic.datos[i] << endl;
    }
    */

    borrarDiccionario(miDic);

    crearDiccionario(miDic);
    crearDiccionario(miDic);
    borrarDiccionario(miDic);
    borrarDiccionario(miDic);
}

void basico2(){
    cartel("agregaPalabra/mostrarPalabras/cuentaPalabras");

    Diccionario miDic = {nullptr, nullptr, 0,0};
    crearDiccionario(miDic);
    agregaPalabra(miDic, "ALGO");
    agregaPalabra(miDic, "ALGUN");

    /*for (int i = 0; i < miDic.util; i++)
    {
        cout << miDic.datos[i] << endl;
    }*/
    

    mostrarPalabras(miDic, 'A');
    

    mostrarPalabras(miDic, 'Z');
    agregaPalabra(miDic, "ZAPATO");
    agregaPalabra(miDic, "ZAPATIN");
    cout << "\n*** Palabras que empiezan con Z" << endl;
    mostrarPalabras(miDic, 'Z');

    cout << " Hay " << cuentaPalabras(miDic, 'A') << " con A " << endl;
    cout << " Hay " << cuentaPalabras(miDic, 'B') << " con B " << endl;
    cout << " Hay " << cuentaPalabras(miDic, 'Z') << " con Z " << endl;
    borrarDiccionario(miDic);
}

void basico3(){
   cartel("Lectura de datos usando redireccion de entrada");

  Diccionario miDic = {nullptr, nullptr, 0,0};
  
  int util_pals; // cant palabras
  
  crearDiccionario(miDic);
  mostrarDiccionario(miDic);
  
  // lectura de palabras desde fichero
  int n;
  string palabra;
  cin >> n;
  for(int j = 0; j < n; j++){
      cin >> palabra;
      agregaPalabra(miDic, palabra);
  }

  mostrarDiccionario(miDic);

  agregaPalabra(miDic, "ZANGANO");
  agregaPalabra(miDic, "ZANGANO");

  mostrarPalabras(miDic, 'Z');

  cout << "\nExiste ZANGANO " << existe(miDic, "ZANGANO") << endl;

  mostrarDiccionario(miDic);
  
  mostrarPalabras(miDic, 'R');
  borraPalabra(miDic, "RELOJ");
  
  mostrarPalabras(miDic, 'R');
 borrarDiccionario(miDic);
}

void redimensionar(){
    cartel("Agregar/borrar forzando redimensionar");
    Diccionario miDic = {nullptr, nullptr, 0,0};
    crearDiccionario(miDic);
    int base = miDic.util;
    string pal;
    cout << "UTILES INI: " << miDic.util << endl;
    for(char letra='A'; letra <= 'Z'; letra++){
        for(char nro = '1'; nro <= '4'; nro++){
            pal = letra;
            pal += nro;
            agregaPalabra(miDic, pal);
        }
    }


    cout << "UTILES 2: " << miDic.util << endl;
    for(char letra='Z'; letra >= 'A'; letra--){
        for(char nro = '1'; nro <= '4'; nro++){
            pal = letra;
            pal += nro;
            borraPalabra(miDic, pal);
        }
    }
    cout << "UTILES 3: " << miDic.util << endl;

borrarDiccionario(miDic);
}

void copiar(){
  cartel("Prueba copia profunda");
  Diccionario otro = {nullptr, nullptr, 0,0};
  Diccionario miDic = {nullptr, nullptr, 0,0};
  crearDiccionario(miDic);
  int base = miDic.util;
  cout << "\nAgregar palabras a diccionario base" << endl;
  string pal;
    for(char letra='A'; letra <= 'Z'; letra++){
        for(char nro = '1'; nro <= '4'; nro++){
            pal = letra;
            pal += nro;
            agregaPalabra(miDic, pal);
        }
    }
  
  agregaPalabra(miDic, "RAMPAS");

  cout << "Copiar a otro diccionario" << endl;
  copiarDiccionario(miDic, otro);

  cout << "COMPROBACIONES" << endl;
  for(char letra = 'A'; letra <= 'Z'; letra++){
    if (cuentaPalabras(miDic, letra) != cuentaPalabras(otro,letra))
        cout << "\nNo coinciden el numero de palabras con la letra " << letra << endl;
  }

  cout << " Borrar palabras añadidas y mostrar " << endl;
  borrarDiccionario(miDic);
  for(char letra='A'; letra <= 'Z'; letra++){
        for(char nro = '1'; nro <= '4'; nro++){
            pal = letra;
            pal += nro;
            borraPalabra(otro, pal);
        }
    }
  mostrarDiccionario(otro);
  borrarDiccionario(otro);

}

int main(){ 
   // llamado a las funciones de prueba
    basico1();
    basico2();
    basico3();
    redimensionar();
    copiar();

}
                 

