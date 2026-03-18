#include <iostream>
#include <cstdlib>

using namespace std;

void mostrar(const int *v, int k)
{
  for (int i = 0; i < k; i++)
    cout << v[i] << ", ";
  cout << endl;
}

void rellenar(int *v, int k, int min, int max)
{
  for (int i = 0; i < k; i++)
    v[i] = (random() % (max - min)) + min;
}

/*
*v es el puntero del array que se introduce
**min **max son punteros de los punteros a *minimo y *maximo que son punteros que apuntaran al maximo y minimo de v
los he puesto como punteros a punteros para hacer mas facilmente el apartado 4


*/
void comparar(int *v, int n, int **min, int **max) /* **min y **max son */
{
  int *p = v;

  // se inicializan en la posicion inicial de v[0] al igual que p
  *min = v;
  *max = v;

  for (int i = 1; i < n; i++)
  {
    p++; // avanzamos posiciones en el array al que se esta apuntando ya que p esta en v[0] al principio

    if (*p < **min)
    {
      *min = p; // ahora si hay algun elemento menor que min se le añadira como el siguiente minimo apuntando a esa celda
    }
    if (*p > **max)
    {
      *max = p;
    }
  }
}

void algoritmo(int *v, int n, int **principio, int **final)
{
  *principio = v;
  *final = v + n - 1;
  int aux;

  while (*principio < *final)
  {
    while (**principio <= v[0] && *principio < *final)
    {
      (*principio)++;
    }

    while (**final > v[0] && *final > *principio)
    {
      (*final)--;
    }

    if (*principio < *final) // Solo se intercambian si *principio todavía está antes de *final.
    {
      aux = **principio;
      **principio = **final;
      **final = aux;
    }
  }
}

int main()
{
  const int N = 10;
  int datos[N];

  // para rellenar el array con valores al azar entre [min, max]
  // utiliza las dos instrucciones siguientes

  srand(time(0));
  rellenar(datos, N, -10, 10);

  int signo = 1;
  for (int i = 0; i < N; i++)
  {
    datos[i] = i * signo;
    signo = signo * -1;
  }

  mostrar(datos, N);

  int *p = &datos[2];
  mostrar(p, 5);

  p = &datos[4];
  mostrar(p, 5);

  int *p1, *p2;
  p1 = &datos[3];
  p2 = &datos[8];
  cout << "Salida 1: " << p2 - p1 << endl;

  p1 = &datos[0];
  cout << "Salida 2: " << p2 - p1 << endl;

  p1 = datos;
  cout << "Salida 3: " << p2 - p1 << endl;

  p1 = &datos[5];
  cout << "Salida 4: " << *p2 << " - " << *p1
       << " = " << *p2 - *p1 << endl;

  // Segundo ejercicio
  const int MAX = 21;
  int vector[MAX];
  rellenar(vector, MAX, -10, 10);
  int usados = 9;

  mostrar(vector, usados);

  int *minimo, *maximo;

  comparar(vector, usados, &minimo, &maximo);

  cout << "1. El maximo es " << *maximo << " y el minimo es " << *minimo << endl;

  comparar(vector, usados / 2, &minimo, &maximo);
  cout << "2. El maximo de la primera mitad es " << *maximo << " y el minimo es " << *minimo << endl;

  int tercio = usados / 3;
  // hacemos vector + 2*tercio para que pase a la posicion del segundo tercio
  comparar(vector + 2 * tercio, tercio, &minimo, &maximo);
  cout << "3. El maximo del segundo tercio es " << *maximo << " y el minimo es " << *minimo << endl;

  comparar(vector, usados, &minimo, &maximo);
  if (minimo < maximo)
  {
    cout << "El minimo aparece antes que el maximo" << endl;
  }
  else
  {
    cout << "El maximo aparece antes que el minimo" << endl;
  }

  // Tercer ejercicio

  const int N2 = 10;
  int E[N2] = {0, 7, -1, 0, 8, 4, -7, -9, 0, -3};

  mostrar(E, N2);

  int *principio, *final;

  algoritmo(E, N2, &principio, &final);

  mostrar(E, N2);

  const int N3 = 20;
  int E2[N3];
  rellenar(E2, N3, -10, 10);
  mostrar(E2, N3);

  algoritmo(E2, N3, &principio, &final);

  mostrar(E2, N3);
}
