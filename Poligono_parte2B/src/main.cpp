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
#include "PoliReg.h"
#include <iostream>
#include <cmath>

using namespace std;
const bool DEBUG = true;

/*
 * 
 */


int main(int argc, char** argv) {
    int maxAst = Asteroide::MAX_AST;
    Asteroide *campoAsteroides = new Asteroide[Asteroide::MAX_AST];// como lo inicializo con MAX_AST con meoria dinamica??
    int uAst = 0; 
    Asteroide *disparos = new Asteroide[Asteroide::MAX_DIS];
    int uDisp = 0;
    Asteroide nave ;
    
    // Mover y rotar los asteroides del campoAsteroides.
    for(int i=0;i<Asteroide::MAX_AST; i++){
        campoAsteroides[i].mover();
        campoAsteroides[i].rotar();
    }
    
    /*Detectar y gestionar colisiones entre asteroides del campoAsteroides.
    Cuando dos asteroides colisionan, simularemos la version m ´ as sen- ´
    cilla del choque elastico que implica el intercambio de velocidades ´
    entre ambos asteroides.*/
    
    //en donde implemento esto porque esto estaria mejor puesto en Asteroide.cpp no???
    
    for(int i=0; i < Asteroide::MAX_AST; i++){
        for(int j=i+1; j < Asteroide::MAX_AST; j++){
            if(campoAsteroides[i].colision(campoAsteroides[j])){
               
                Punto2D v1 = campoAsteroides[i].getVelocidad();
                Punto2D v2 = campoAsteroides[j].getVelocidad();

                if(DEBUG){
                cout << i << j <<"Antes de intercambiar" <<  campoAsteroides[i].getVelocidad() <<  ", " << campoAsteroides[j].getVelocidad() << endl;    
                }
                
                campoAsteroides[i].setVelocidad(v2);
                campoAsteroides[j].setVelocidad(v1);
                
                if(DEBUG){
                cout << i << j << "Despues de intercambiar" <<  campoAsteroides[i].getVelocidad() <<  ", " <<  campoAsteroides[j].getVelocidad() << endl;    
                }
            } 
        }
    }
    
    
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
    delete[] campoAsteroides;
    delete[] disparos;
    return 0;
    
   
}

