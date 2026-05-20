

#include <iostream>
/*
 
 * IMPLEMENTACION DEL EJERCICIO DE TRAMPAS Y CUCARACHAS
 * 
 * lista de puntos
 * lista de rectangulos
 * analizar datos de cuantos puntos caen en cada rectangulo
 */

#include "Punto2D.h"
#include "Rect.h"
#include <cctype>
#include <random>


using u32    = uint_least32_t;
using engine = std::mt19937;



using namespace std;


/* Función auxiliar que rellena un array de tipo Punto2D con valores generados al azar
* cada coordenada de cada punto, se genera en el intervalo [1,50]
 */
void generarPuntos(Punto2D vp[], int np){
  std::random_device os_seed;
  const u32 seed = os_seed();

  engine generator( seed );
  std::uniform_int_distribution< u32 > distribute( 1, 50 );
  for(int i = 0; i < np; i++){
        vp[i].x = distribute( generator );
        vp[i].y = distribute( generator );
    }

}

/*
 * Función auxiliar que rellena un array de Rectangulos con valores generados al azar
 * 
 */
void generarRectangulos(Rect vr[], int nr, int maxBase, int maxAltura){
    // generar nr rectangulos al azar en un espacio (0,0), (maxX. maxY)
    // con tamaño maximo maxBase x maxAltura

	// genero el vertice arriba-izq y luego, a esa posicion le sumo otro valor al azar
 std::random_device os_seed;
  const u32 seed = os_seed();

  engine generator( seed );
  std::uniform_int_distribution< u32 > distribute( 1, maxBase / 2 );
  int x1, y1, x2, y2;
  for(int i = 0; i< nr; i++){
	  x1 = distribute(generator);
	  y1 = distribute(generator);
	  x2 = x1 + distribute(generator);
	  y2 = y1 + distribute(generator);
	  if (y2 < 1)
		  y2 = 1;
	  vr[i] = {x1, y1, x2, y2};
  }


}

/*
 * Función que devuelve el índice del primer rectángulo del array que contiene al punto actual
 * Si el punto no está contenido en ningún rectángulo, devuelve -1
 */
int nroRectangulo(const Rect vr[], int nr, const Punto2D & actual){
    int rta = -1;
    for(int i = 0; i < nr && rta == -1; i++){
        if (estaDentro(vr[i], actual)){
            rta = i;
        }
    }
    return rta;
}

const int MAX_P = 100;
const int MAX_R = 5;

// el programa lee los datos usando redirección de entrada 
// o los puede generar al azar usando las funciones anteriores

int main() {
    Punto2D vp[MAX_P];
    int np = 10;

   // generarPuntos(vp, np); // las cucarachas
    cin >> np;
    int x, y;
    for(int i = 0; i < np; i++){
        cin >> x >> y;
        vp[i] = {x, y};
        cout << toString(vp[i]) << endl;
}

    Rect vr[MAX_R];
    int nr = 5;

    //generarRectangulos(vr, nr, 30, 30); // las trampas
    cin >> nr;  
    for(int i = 0; i < nr; i++){
        cin >> x >> y;
        vr[i].ul = {x, y};
        cin >> x >> y;
        vr[i].dr = {x, y};
        cout << toString(vr[i]) << endl;
    }


/* Cada punto es una cucaracha y cada rectángulo, una trampa
 * Hay que contar cuantos puntos "caen" en cada rectangulo y cuantos "caen" fuera
* El procesamiento es simple: para cada punto, ver a que rectangulo pertenece
* Utilizaremos un array de contadores asociado a cada rectangulo
* Este array tendrá el mismo tamaño que el array de rectángulos;
*/
    int contar[nr] = {0}; //array de contadores

    int indice;
    int fuera = 0;
    // para cada punto
    for(int p = 0; p < np; p++){
        Punto2D actual = vp[p];

        // ¿A qué rectangulo pertenece?  -1 si ninguno
        indice = nroRectangulo(vr, nr, actual);
        if (indice >= 0)
            contar[indice]++; // punto en rectángulo
        else
            fuera++; // punto fuera

        cout << "Cucaracha " << toString(actual) << "  \t->  ";
        if (indice >= 0)
            cout << "en trampa " << indice+1 << endl;
        else
            cout << "libre " << endl;

    }

    for(int i = 0; i < nr; i++){
        cout << "Cucarachas en trampa " << i + 1 << "  :" << contar[i] << endl;
    }
    cout << "Cucarachas libres: " << fuera << endl;


    return 0;
}

