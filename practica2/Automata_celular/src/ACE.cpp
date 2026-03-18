

#include <iostream>

#define BLANCO "\33[30;47m" // fondo blanco
#define NEGRO "\33[30;40m"  // fondo negro
#define ROJO "\33[30;41m"   // fondo rojo
#define VERDE "\33[30;42m"  // fondo verde
#define AZUL "\33[30;44m"   // fondo azul
#define RESET "\033[m"

#include "ACE.h"

void mostrar(const bool state[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (state[i])
        {
            cout << BLANCO << " " << RESET;
        }
        else
        {
            cout << NEGRO << " " << RESET;
        }
        cout << endl;
    }
}
