#include <iostream>
#include <cstdlib>
#include <cstring>
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
// Saber cuantos caracteres tiene el texto T
int longitud(const char s[])
{
  int cont = 0;

  while (s[cont] != '\0')
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

  es_letra_actual = s[j] != ' ';
  if (j > 0)
    hay_sep_previo = (s[j - 1] == ' ');

  return (es_letra_actual && hay_sep_previo);
}

// funcion privada.
// el valor j siempre debe estar en el rango correcto
bool terminaPalabra(const char s[], int j)
{
  // termina una palabra si el carácter en la posición j es distinto de espacio
  // y, además, en la posición j+1 aparece un espacio o el terminador (es la última palabra)

  bool es_letra_actual = (s[j] != ' ');
  bool hay_sep_sig = (s[j + 1] == ' ') || (s[j + 1] == '\0');

  return (es_letra_actual && hay_sep_sig);
}

void devolverPalabras(char s[], char *ptrIni[])
{
  int long1 = longitud(s);
  int contador = 0;

  for (int i = 0; i < long1; i++)
  {
    if (empiezaPalabra(s, i))
    {
      ptrIni[contador] = &s[i];
      contador++;
    }
    else if (terminaPalabra(s, i))
    {
      ptrIni[contador] = &s[i];
      contador++;
    }
  }
}

// Saber cuantas palabras tiene el texto T.
int cuentaPalabras(const char msg[])
{
  int cont = 0;
  int i = 0;
  while (msg[i] != '\0')
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
    while (msg[i] != '\0')
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
    while (s[posicion] != ' ' && s[posicion] != '\0')
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
    salida[0] = '\0';
  }
  else
  {
    for (int i = 0; i < longitud_pal; i++)
    {
      salida[i] = msg[posicion];
      posicion++;
    }

    salida[longitud_pal] = '\0';
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

  // ejercicio 5

  char cstring[100];
  strcpy(cstring, "UNA CASA PERDIDA EN ALPUJARRAS");
  char *ptrIni[100];
  char nueva[100];

  devolverPalabras(cstring, ptrIni);

  cout << "La cadena: " << *ptrIni << " contiene la siguientes palabras " << endl;
  int nro = 1;
  int totalPalabras = cuentaPalabras(cstring);

  while (nro <= totalPalabras)
  {
    extraePalabra(*ptrIni, nro, nueva); // extrae la palabra nro-ésima en el buffer
    cout << nro << " -> " << nueva << " (" << longitud(nueva) << ")\n";
    nro++;
  }
}
