/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: juan
 *
 * Created on 5 de mayo de 2026, 23:29
 */

#include <cstdlib>
#include "Asteroide.h"
#include "configuracion.h"
#include "raylib.h"
#include "Minijuego.h"
#include <iostream>
#include <cmath>

using namespace std;
const bool DEBUG = true;
/*
 * 
 */

int main(int argc, char** argv) {
    
    Minijuego juego;
    
    
    // Mover y rotar los asteroides del campoAsteroides.
    juego.moverYrotar();
    
    /*Detectar y gestionar colisiones entre asteroides del campoAsteroides.
    Cuando dos asteroides colisionan, simularemos la version mas sen-
    cilla del choque elastico que implica el intercambio de velocidades ´
    entre ambos asteroides.*/
    
    
    juego.detectarColisiones_Asteroides();
    
    
    /*Detectar y gestionar colisiones entre asteroides y los bordes de la
    pantalla. Cuando un asteroide llegue al borde de la pantalla tiene
    dos opciones: 1) rebotar o 2) aparecer por el lado contrario.*/
    
    juego.detectarColisiones_bordes();
    
    
    /*Hacer una funcion para pintar los vertices de los asteroides*/
    
    
    
    /*
     Mover los misiles en disparos. Si un misil sale de la pantalla,
     debe desaparecer.
     */
    
    // if(IsKeyPressed(KEY_A)){
    //     juego.disparar();
    // }
    
    for(int i=0; i<juego.getuDisp(); i++){
        cout << juego.getDisparos(i) << endl;
    }
    
    for(int i=0; i<juego.getuDisp(); i++){
        cout << "Antes de moverlos " << juego.getDisparos(i) << endl;
    }
    
    juego.detectarMisiles_bordes();
    
    for(int i=0; i<juego.getuDisp(); i++){
        cout << "Despues de mover los disparos " << juego.getDisparos(i) << endl;
    }
    
    
    /*
     Detectar y gestionar colisiones entre misiles (del array disparos) y
    el campoAsteroides. El comportamiento esta definido al comien- ´
    zo de la seccion. Cuando tenga que detectar si un disparo ´ m colisiona con algun asteroide ´ a debe comenzar a recorrer campoAsteroides
    desde la ultima posici ´ on´ util del array (en otro caso, puede tener pro- ´
    blemas con el borrado).
     */
    juego.colision_misiles_Asteroides();
    
    /*
     Detectar y gestionar colision entre la ´ nave y algun asteroide.
     */
    
    
    /*
     Detectar y gestionar las teclas pulsadas: >, mover nave a la derecha,
    <, a la izquierda, ’A’, disparar. Cuando se dispara, se crea un nuevo
    objeto asteroide con la misma posicion que la nave y la velocidad ´
    indicada anteriormente. Luego, este nuevo objeto se anade al array ˜
    disparos
     */
    
    



    // while (!WindowShouldClose()) {
    //     juego.update();
    //     BeginDrawing();
    //     //juego.pintar();
    //     EndDrawing();
    // }   
    
    
   
    return 0;
    
   
}

