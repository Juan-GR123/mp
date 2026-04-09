/*
 * File:   test.cpp
 * Author: David A. Pelta
 * Fichero de pruebas para el módulo diccionario
 * 
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "diccionario.h"
#include <cstring>

using namespace std;


TEST_CASE("Pruebas Basicas") {
    SUBCASE("valgrind creacion/borrado"){
    Diccionario miDic = {nullptr, nullptr, 0,0};
    crearDiccionario(miDic);
    borrarDiccionario(miDic);

    crearDiccionario(miDic);
    crearDiccionario(miDic);
    borrarDiccionario(miDic);
    borrarDiccionario(miDic);
}
    SUBCASE("Prueba crear/borrar") {
        Diccionario miDic = {nullptr, nullptr, 0,0};
        crearDiccionario(miDic);
        int fin = ('Z' - 'A' + 2);
        CHECK(miDic.util == fin);
        CHECK(miDic.cap == N_INDICE * 2);
        CHECK(miDic.indice[0] == &(miDic.datos[0]));
        CHECK(miDic.indice[fin-1] == &(miDic.datos[fin-1]));
        borrarDiccionario(miDic);
    }

    SUBCASE("Prueba agrega/borra sin redimension") {
        Diccionario miDic = {nullptr, nullptr, 0,0};
        crearDiccionario(miDic);
        int iniSize = miDic.util;
        agregaPalabra(miDic, "Base");
        CHECK(miDic.util == iniSize+1);
        agregaPalabra(miDic, "Casa");
        CHECK(miDic.util == iniSize+2);
        agregaPalabra(miDic, "Casa");
        CHECK(miDic.util == iniSize+2);
        borraPalabra(miDic, "Base");
        CHECK(miDic.util == iniSize+1);
        borraPalabra(miDic, "Base");
        borraPalabra(miDic, "Casa");
        CHECK(miDic.util == iniSize);
        borrarDiccionario(miDic);
    }
    
    SUBCASE("Prueba existe/agrega/borra") {
        Diccionario miDic = {nullptr, nullptr, 0,0};
        crearDiccionario(miDic);
        int iniSize = miDic.util;
        agregaPalabra(miDic, "Base");
        agregaPalabra(miDic, "Zangano1");
        agregaPalabra(miDic, "Zangano2");

        CHECK(existe(miDic,"Base") == true);
        CHECK(existe(miDic,"Zangano2") == true);

        borraPalabra(miDic, "Base");
        CHECK(existe(miDic,"Base") == false);
        CHECK(existe(miDic,"Zangano2") == true);
        CHECK(existe(miDic,"XXXX") == false);
        borrarDiccionario(miDic);
   }
    
}

TEST_CASE("con Redimension") {
    SUBCASE("Agrega/Borra"){
        Diccionario miDic = {nullptr, nullptr, 0,0};
        crearDiccionario(miDic);
        int base = miDic.util;
        string pal;
        for(char letra='A'; letra <= 'Z'; letra++){
            for(char nro = '1'; nro <= '4'; nro++){
                pal = letra;
                pal += nro;
                agregaPalabra(miDic, pal);
            }
        }
        CHECK(miDic.util == base + ('Z'-'A'+1) * 4);

        cout << "UTILES: " << miDic.util << endl;
        for(char letra='Z'; letra >= 'A'; letra--){
            for(char nro = '1'; nro <= '4'; nro++){
                pal = letra;
                pal += nro;
                borraPalabra(miDic, pal);
            }
        }
        CHECK(miDic.util == base);

        borrarDiccionario(miDic);
    }
} 

TEST_CASE("Extraer palabras") {
    SUBCASE("extrae"){
        Diccionario miDic = {nullptr, nullptr, 0,0};

        crearDiccionario(miDic);

        agregaPalabra(miDic, "Z1");
        agregaPalabra(miDic, "Z2");
        agregaPalabra(miDic, "Z3");
        agregaPalabra(miDic, "Z4");


        int utiles;
        string* salida = extraePalabras(miDic, 'Z', utiles);

        CHECK(salida[0] == "Z");
        CHECK(salida[2] == "Z2");
        delete [] salida;
        salida = extraePalabras(miDic, 'A', utiles);
        CHECK(utiles == 1);
        delete [] salida;

        borrarDiccionario(miDic);
    }

    SUBCASE("extrae"){
        Diccionario miDic = {nullptr, nullptr, 0,0};
        Diccionario resumen = {nullptr, nullptr, 0,0};

        crearDiccionario(miDic);
        crearDiccionario(resumen);
        int iniSize = resumen.util;

        agregaPalabra(miDic, "Z1");
        agregaPalabra(miDic, "Z2");
        agregaPalabra(miDic, "Z3");
        agregaPalabra(miDic, "Z4");

        agregaPalabra(miDic, "C1");
        agregaPalabra(miDic, "C2");
        agregaPalabra(miDic, "C3");
        agregaPalabra(miDic, "C4");


        int utiles;
        string* salida = extraePalabras(miDic, 'Z', utiles);
        for(int i = 0; i < utiles; i++)
            agregaPalabra(resumen, salida[i]);

        CHECK(cuentaPalabras(miDic, 'Z') == 5);
        delete [] salida;

        salida = extraePalabras(miDic, 'C', utiles);
        for(int i = 0; i < utiles; i++)
            agregaPalabra(resumen, salida[i]);

        CHECK(cuentaPalabras(miDic, 'C') == 5);
        CHECK(resumen.util == iniSize + 8);

        delete [] salida;

        borrarDiccionario(miDic);
        borrarDiccionario(resumen);
    }

}
