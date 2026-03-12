/*
Sugerencias y recomendaciones

Puedes considerar que un ACE tendra siempre 100 celdas.

La tabla de reglas se puede representar mediante un array bool
reglas[8].

Cuando transformes el n ´umero de la regla a binario, recuerda alma-
cenar los bits resultantes desde la posici ´on 0 hasta la 7 en el array
reglas.

El vecindario de una celda es un numero binario de tres d´ıgitos. Si
se transforma dicho numero al valor decimal, entonces se obtiene un
numero entero que servira como ındice para acceder a las reglas.
Por ejemplo, el patr ´on 011 se transforma en el valor 3, por tanto, el
nuevo valor para la celda es reglas[3]

*/

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
