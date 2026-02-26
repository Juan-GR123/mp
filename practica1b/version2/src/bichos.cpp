#include <iostream>
#include <cmath>
#include <string>
#include "punto2d.h"
#include "rectangulo.h"

using namespace std;

int main()
{
    int n;
    cout << "Introduce el número de cucarachas\n";
    cin >> n;

    Punto cucarachas[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x, y;
        cout << "Introduce las coordenadas de la cucaracha " << i << "\n";
        cin >> x >> y;
        cucarachas[i].setX(x);
        cucarachas[i].setY(y);
    }

    int t;
    cout << "Introduce el número de trampas\n";
    cin >> t;

    Rectangulo trampas[t];

    for (int i = 0; i < t; i++)
    {
        /* code */
        Punto px, py;
        int x1, y1, x2, y2;
        cout << "Introduce del rectangulo " << i << " los primeros dos puntos de la parte izquierda superior del rectangulo: \n";
        cin >> x1 >> y1;
        px.setX(x1);
        px.setY(y1);
        trampas[i].setX(px);
        cout << "Ahora vuelve a introducir otros dos puntos de la parte derecha inferior: \n";
        cin >> x2 >> y2;
        py.setX(x2);
        py.setY(y2);
        trampas[i].setY(py);
    }

    int cucarachas_sueltas = 0;
    int contador_t[t];
    int atrapadas = 0;

    // Inicializar contadores de trampas
    for (int i = 0; i < t; i++)
    {
        contador_t[i] = 0;
    }

    // Recorremos cucarachas
    for (int j = 0; j < n; j++)
    {
        bool capturada = false;

        // Miramos en qué trampa cae
        for (int i = 0; i < t; i++)
        {

            if (trampas[i].estaDentro(cucarachas[j]) && !capturada)
            {
                cout << "  La cucaracha " << j << " esta dentro de la trampa " << "->" << i << "\n";
                contador_t[i]++;
                atrapadas++;
                capturada = true;
            }
        }

        if (!capturada)
        {
            cucarachas_sueltas++;
        }
    }

    cout << "numero de cucarachas atrapadas: " << atrapadas << "\n";

    for (int i = 0; i < t; i++)
    {
        /* code */
        cout << "trampa numero " << "->" << i << " \n";
        cout << "Numero de cucarachas capturadas: " << contador_t[i] << " \n";
    }

    cout << "numero de cucarachas sueltas:  " << cucarachas_sueltas << " \n";
}