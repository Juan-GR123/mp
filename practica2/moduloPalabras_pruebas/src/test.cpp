/*
 * File:   main.cpp
 * Author: David A. Pelta
 *
 * Created on 10 de marzo de 2023
 */

/*
NOMBRE Y APELLIDOS: Juan García Rosales
DNI:
GRUPO DE PRÁCTICAS: Miércoles
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// #include <iostream>
#include "palabras.h"
#include <cstring>

using namespace std;

TEST_CASE("Pruebas Basicas")
{

    SUBCASE("Prueba longitud")
    {
        char cad1[MAX_SIZE] = "abcdefg";
        char cad2[MAX_SIZE] = "abcdefg";
        CHECK(longitud(cad1) == longitud(cad2));
        cad2[5] = '\0';
        CHECK(longitud(cad1) != longitud(cad2));
        cad1[0] = '\0';
        CHECK(longitud(cad1) == 0);
    }

    SUBCASE("Nro palabras")
    {
        char cad1[MAX_SIZE] = "1 22 333 4444 55555";
        int inicios[] = {0, 2, 5, 9, 14};
        for (int i = 0; i < 5; i++)
        {
            CHECK(cuentaPalabras(cad1) == 5 - i);
            cad1[inicios[4 - i]] = '\0';
        }
    }

    SUBCASE("Pos inicio")
    {
        char cad1[MAX_SIZE] = "1 22 333 4444 55555";
        int inicios[] = {0, 2, 5, 9, 14};
        for (int i = 0; i < 5; i++)
        {
            CHECK(posPalabra(cad1, i + 1) == inicios[i]);
        }
    }

    SUBCASE("longitud palabras")
    {
        char cad[MAX_SIZE];
        cad[0] = '\0';
        CHECK(longPalabra(cad, 0) == -1);
        CHECK(longPalabra(cad, 1) == -1);
        CHECK(longPalabra(cad, 2) == -1);

        char cad1[MAX_SIZE] = "1 22 333 4444 55555 666666";
        for (int i = 0; i < 6; i++)
        {
            CHECK(longPalabra(cad1, i + 1) == i + 1);
        }
    }
}

TEST_CASE("extrae/agrega/invierte 1")
{
    SUBCASE("extrae")
    {
        char out[MAX_SIZE];
        char msg[MAX_SIZE] = "1 22 333 4444 55555 666666";
        for (int i = 0; i < 6; i++)
        {
            extraePalabra(msg, i + 1, out);
            CHECK(longitud(out) == i + 1);
        }

        extraePalabra(msg, 11, out);
        CHECK(longitud(out) == 0);
    }

    SUBCASE("extrae/agrega/invierte 2")
    {
        char aux[MAX_SIZE];
        char salida1[MAX_SIZE];
        char salida2[MAX_SIZE];
        char msg[MAX_SIZE] = "1 22 333 4444 55555 666666";
        int cont = 0;
        for (int i = 0; i < 6; i++)
        {
            extraePalabra(msg, i + 1, aux);
            cont += longitud(aux);
            agregaPalabra(salida1, aux);
        }

        delReves(msg, salida2);
        CHECK(longitud(msg) == cont + 5);
    }

    SUBCASE("extrae/ invierte")
    {
        char salida[MAX_SIZE];
        char msg[MAX_SIZE] = "1 22 333 4444 55555 666666";
        int cont = 0;
        delReves(msg, salida);
        // cambio los guiones por espacios
        while (salida[cont] != TERMINADOR)
        {
            if (salida[cont] == '-')
                salida[cont] = ' ';
            cont++;
        }

        CHECK(cuentaPalabras(msg) == cuentaPalabras(salida));
        char pal1[MAX_SIZE];
        char pal2[MAX_SIZE];

        for (int i = 0; i < 6; i++)
        {
            extraePalabra(msg, i + 1, pal1);
            extraePalabra(salida, 6 - i, pal2);
            CHECK(longitud(pal1) == longitud(pal2));
        }
    }
}