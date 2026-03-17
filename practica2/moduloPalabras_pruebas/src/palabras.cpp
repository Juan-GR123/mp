
/*
 * File:   palabras.cpp
 * Author: David Pelta
 *
 * Created on 10 de marzo de 2023,
 */

/*
Se pide implementar un modulo ´ palabras con funciones que permitan:
*/

#include "palabras.h"

// Saber cuantos caracteres tiene el texto T
int longitud(const char s[])
{
    int cont = 0;

    while (s[cont] != TERMINADOR)
        cont++;

    return cont;
}

// funcion privada.
// el valor j siempre debe estar en el rango correcto
bool empiezaPalabra(const char s[], int j)
{
    // empieza una palabra si el carácter en la posición j es distinto de espacio
    // y, además, si j > 0, en la posición anterior había un espacio

    bool es_letra_actual;
    bool hay_sep_previo = true;

    es_letra_actual = s[j] != SEP;
    if (j > 0)
        hay_sep_previo = (s[j - 1] == SEP);

    return (es_letra_actual && hay_sep_previo);
}

// funcion privada.
// el valor j siempre debe estar en el rango correcto
bool terminaPalabra(const char s[], int j)
{
    // termina una palabra si el carácter en la posición j es distinto de espacio
    // y, además, en la posición j+1 aparece un espacio o el terminador (es la última palabra)

    bool es_letra_actual = (s[j] != SEP);
    bool hay_sep_sig = (s[j + 1] == SEP) || (s[j + 1] == TERMINADOR);

    return (es_letra_actual && hay_sep_sig);
}
// Saber cuantas palabras tiene el texto T.
int cuentaPalabras(const char msg[])
{
    int cont = 0;
    int i = 0;
    while (msg[i] != TERMINADOR)
    {
        if (empiezaPalabra(msg, i))
        {
            cont++;
        }
        i++;
    }

    return cont;
}

// Obtener la posicion de inicio de la palabra k- ´ esima. ´
int posPalabra(const char msg[], int nroPal)
{
    int i = 0;
    int palabras = cuentaPalabras(msg);
    int cont_sep = 0;

    if (nroPal <= palabras)
    {
        while (msg[i] != TERMINADOR)
        {

            if (empiezaPalabra(msg, i))
            {
                cont_sep++;
            }

            if (cont_sep == nroPal)
            {
                return i; // Esta será la posicion de la palabra que no han indicado
            }
            i++;
        }
    }

    return -1;
}

// Calcular la longitud de la palabra k-esima de T.
int longPalabra(const char s[], int nroPal)
{

    int posicion = posPalabra(s, nroPal);
    int cont = 0;

    if (posicion == -1)
    {
        return -1;
    }
    else
    {
        while (s[posicion] != SEP && s[posicion] != TERMINADOR)
        {
            cont++;
            posicion++;
        }

        return cont;
    }
}

// Extraer la palabra k-esima de ´ T.
void extraePalabra(const char msg[], int nroPal, char salida[])
{
    int posicion = posPalabra(msg, nroPal);
    int longitud_pal = longPalabra(msg, nroPal);

    if (posicion == -1)
    {
        salida[0] = TERMINADOR;
    }
    else
    {
        for (int i = 0; i < longitud_pal; i++)
        {
            salida[i] = msg[posicion];
            posicion++;
        }

        salida[longitud_pal] = TERMINADOR;
    }
}

// Construir el texto T inv que contendra las palabras de T en orden inverso. Las palabras estaran separadas por el caracter ’-’.
void delReves(const char msg[], char msg_reves[])
{
    int Numero_palabras = cuentaPalabras(msg);
    char palabra[longitud(msg) + 1]; // le pongo el mismo numero de celdas que msg mas 1 que es para el 0/
    int Pos_reves = 0;

    for (int i = Numero_palabras; i > 0; i--)
    {
        extraePalabra(msg, i, palabra);

        int j = 0;

        while (palabra[j] != TERMINADOR)
        {
            msg_reves[Pos_reves] = palabra[j];
            Pos_reves++;
            j++;
        }

        if (i > 1) // en la ultima palabra que es la de la posicion i=1 no se le añade un -
        {
            msg_reves[Pos_reves] = '-';
            Pos_reves++;
        }
    }
    msg_reves[Pos_reves] = TERMINADOR;
}

// Agregar una palabra s al texto T.
void agregaPalabra(char msg[], const char pal[])
{

    int caracteres = longitud(msg);
    int caracteres_extras = longitud(pal);

    // msg[caracteres] = ' '; // sustituyo el '\0' por un ' '
    // caracteres++;

    for (int pos = 0; pos < caracteres_extras; pos++)
    {
        msg[caracteres] = pal[pos];
        caracteres++;
    }

    msg[caracteres] = TERMINADOR;
}
