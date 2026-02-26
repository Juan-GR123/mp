#include <iostream>
using namespace std;

const int FIL = 20, COL = 30;
int util_fil = 7, util_col = 12;

int busca_sec(const double array[], int utilArray, double elem)
{
    for (int i = 0; i < utilArray; i++)
    {
        if (array[i] == elem)
            return i;
    }
    return -1;
}

// Versión 1: búsqueda fila por fila
void busca_matriz(const double m[][COL], int utilF, int utilC,
                  double elemento, int &posFila, int &posCol)
{
    posFila = -1;
    posCol = -1;
    for (int f = 0; (f < utilF) && (posCol == -1); f++)
    {
        posCol = busca_sec(m[f], utilC, elemento);
        if (posCol != -1)
            posFila = f;
    }
}

// Versión 2: búsqueda tratando la matriz como un array lineal
void busca_matriz_lineal(const double m[][COL], int utilF, int utilC,
                         double elemento, int &posFila, int &posCol)
{

    posFila = -1;
    posCol = -1;

    int encontrado = busca_sec(m[0], utilF * utilC, elemento); // aqui se recorre todo el array como si fuera una fila entera

    if (encontrado != -1)
    {
        posFila = encontrado / utilC;
        posCol = encontrado % utilC;
    }
}

int main()
{
    double m[FIL][COL];

    // Rellenamos la matriz con valores de ejemplo
    for (int f = 0; f < util_fil; f++)
    {
        for (int c = 0; c < util_col; c++)
        {
            m[f][c] = f * 10 + c; // valores fáciles de identificar
        }
    }

    double elemento;
    cout << "Introduce el elemento a buscar: ";
    cin >> elemento;

    int fila, columna;

    // Llamada a la función
    busca_matriz(m, util_fil, util_col, elemento, fila, columna);
    // busca_matriz_lineal(m, util_fil, util_col, elemento, fila, columna);

    // Mostrar resultado
    if (fila != -1)
        cout << "Encontrado en fila " << fila << " y columna " << columna << endl;
    else
        cout << "Elemento no encontrado" << endl;

    return 0;
}