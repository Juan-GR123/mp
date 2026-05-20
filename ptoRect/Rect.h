
/*
 * File:   Rect.h
* Author: David A. Pelta - Metodologías de la Programación
 * Implementación básica del tipo Rectangulo (Rect)
 * 
 *  
 */

#include "Punto2D.h"
#include <string>

#ifndef RECT_H
#define RECT_H

struct Rect {
    Punto2D ul; // Esquina superior izquierda
    Punto2D dr; // Esquina inferior derecha
};

/**
 * @brief Convierte el rectángulo a una cadena de texto.
 * @param r1 Rectángulo a convertir.
 * @return String con el formato "[(x1, y1), (x2,y2)]".
 */

std::string toString(const Rect & r1);

/**
 * @brief Calcula el área del rectángulo.
 * @param r1 Rectángulo 
 * @return Valor flotante que representa el área.
 */
float area(const Rect & r1);

/**
 * @brief Calcula el perímetro del rectángulo.
 * @param r1 Rectángulo del cual calcular el perímetro.
 * @return Valor flotante que representa el perímetro.
 */
float perimetro(const Rect & r1);

/**
 * @brief Compara dos rectángulos basándose en su área.
 * @param r1 Primer rectángulo.
 * @param r2 Segundo rectángulo.
 * @return true si el área de r1 es estrictamente mayor que la de r2.
 */
bool esMayor(const Rect & r1, const Rect & r2);

/**
 * @brief Comprueba si un punto se encuentra dentro de los límites del rectángulo.
 * @param r1 Rectángulo que define los límites.
 * @param p Punto a evaluar.
 * @return true si el punto está contenido en el rectángulo, false en caso contrario.
 */
bool estaDentro(const Rect & r1, const Punto2D & p);

#endif /* RECT_H */

