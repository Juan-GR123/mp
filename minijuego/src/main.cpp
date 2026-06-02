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
    
    /*Detectar y gestionar colisiones entre asteroides del campoAsteroides.
    Cuando dos asteroides colisionan, simularemos la version mas sen-
    cilla del choque elastico que implica el intercambio de velocidades ´
    entre ambos asteroides.*/
    
    
    /*Detectar y gestionar colisiones entre asteroides y los bordes de la
    pantalla. Cuando un asteroide llegue al borde de la pantalla tiene
    dos opciones: 1) rebotar o 2) aparecer por el lado contrario.*/
    
    /*
     Mover los misiles en disparos. Si un misil sale de la pantalla,
     debe desaparecer.
     */
    
    /*
     Detectar y gestionar colisiones entre misiles (del array disparos) y
    el campoAsteroides. El comportamiento esta definido al comien- ´
    zo de la seccion. Cuando tenga que detectar si un disparo ´ m colisiona con algun asteroide ´ a debe comenzar a recorrer campoAsteroides
    desde la ultima posici ´ on´ util del array (en otro caso, puede tener pro- ´
    blemas con el borrado).
     */
    
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
    
    
    //HACER:
    /*
     -Considere la posibilidad de cambiar la posicion de la nave a la izquierda, derecha, arriba o abajo //hecho
     
     -Implemente la posibilidad de disponer de varias “vidas”.//hecho
     
     - Tambien he añadido que la nave no pueda salir de la pantalla
    
     */
    InitWindow(max_X, max_Y, "Asteroides");
    SetTargetFPS(20);
    Texture2D corazon = LoadTexture("./res/heart-full.png");// Configura tu ruta correspondiente hasta donde tengas el proyecto con la imagen
    Texture2D corazon_vacio = LoadTexture("./res/heart.png");
    
    while (!WindowShouldClose()) {

        
        
        if(!gameOver && !campeon){
            if (IsKeyDown(KEY_LEFT)) {
               juego.mover_nave(-5,0);
             }

            if (IsKeyDown(KEY_RIGHT)) {
                juego.mover_nave(5,0);
            }
            
            if(IsKeyDown(KEY_UP)){
                juego.mover_nave(0,-5);
            }
            
            if(IsKeyDown(KEY_DOWN)){
                juego.mover_nave(0,5);
            }

            if (IsKeyPressed(KEY_A)) {
                juego.disparar();
            }
            
            juego.update();
        }
            
        BeginDrawing();

        ClearBackground(RAYWHITE);
            
        juego.pintar();
        
        
        for(int i = 0; i < MAX_VIDAS; i++){
            
            if(i < vidas){
                DrawTexture(corazon, 10 + i * 40, 10, WHITE);
            }else{
                DrawTexture(corazon_vacio, 10 + i * 40, 10, WHITE);
            }
        }
       
        if(gameOver){
            DrawText("GAME OVER", max_X/2 - 120, max_Y/2 - 50 , 40, RED);
            DrawText("Pulsa la barra espaciadora para reiniciar", max_X/2 - 200, max_Y/2, 20, DARKGRAY);
        }
        
        if(campeon){
            DrawText("YOU WIN", max_X/2 - 100, max_Y/2 - 50, 40, GREEN);
            DrawText("¡Felicidades has ganado!", max_X/2 - 140, max_Y/2, 20, DARKGRAY);
        }
            
       EndDrawing();
        
        if((gameOver && IsKeyPressed(KEY_SPACE)) || (campeon && IsKeyPressed(KEY_SPACE))){
           juego.reiniciarJuego();
        }
        
       
    }

    //se ve que hace falta quitar las texturas al final del programa para que no haya fugas de datos
    UnloadTexture(corazon);
    UnloadTexture(corazon_vacio);
    
    CloseWindow();
    
    return 0;
    
   
}

