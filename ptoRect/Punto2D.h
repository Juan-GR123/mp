
/* 
 * File:   Punto2D.h
* Author: David A. Pelta - Metodologías de la Programación
 * Implementación del tipo Punto2D
 * 
 */

#ifndef PUNTO2D_H
#define PUNTO2D_H

#include <iostream>

struct Punto2D{
    int x,y;
};
/**
 * @brief Convierte un punto a su representación en cadena de texto.
 * @param p El punto a convertir.
 * @return Una cadena con el formato "(x, y)".
 */
std::string toString(const Punto2D & p);

/**
 * @brief Calcula la distancia euclídea entre dos puntos.
 * @param p1 Primer punto.
 * @param p2 Segundo punto.
 * @return La distancia como un valor de punto flotante.
 */
float distancia(const Punto2D & p1, const Punto2D & p2);

/**
 * @brief Calcula el punto medio entre dos puntos dados.
 * @param p1 Primer punto.
 * @param p2 Segundo punto.
 * @param rta [out] Referencia donde se almacenará el punto resultante.
 */
void puntoMedio(const Punto2D & p1, const Punto2D & p2, Punto2D & rta);

#endif /* PUNTO2D_H */

