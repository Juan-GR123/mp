/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   PoliReg.cpp
 * Author: juan
 *
 * Created on 5 de mayo de 2026, 23:30
 */

#include <cstdlib>
#include "PoliReg.h"
#include <iostream>
#include <string>
#include <cmath>

const bool DEBUG = false;

using namespace std;

/*
 * 
 */

const float PoliReg::MAX_RADIO = 200.0;
const float PoliReg::MIN_RADIO = 15.0;
const int PoliReg::MAX_VERT = 200;
const int PoliReg::MIN_VERT = 3;
const double PoliReg::PI=3.14159;

/*
 PoliReg(): Constructor sin parametros. Genera un poligono con
N=MIN VERT vertices, ´ centro en la posicion´ (0, 0) y
radio = MIN RADIO.
 */
PoliReg::PoliReg(){
    N = MIN_VERT;
    centro.setXY(0,0);
    radio = MIN_RADIO;
    vertices=nullptr;
    reservaMemoria(N);
    generaVertices(); 
}

/*
 PoliReg(int nVert, const Punto2D & centro, float r):
Constructor con parametros. Genera un pol ´ ´ıgono de nVert vertices, ´
inscrito en una circunferencia con origen en centro y de radio r.
Si el numero de vertices o el radio est ´ an fuera de los l ´ ´ımites preestablecidos, entonces se fijan a MIN VERT o MIN RADIO, respectivamente
 */
PoliReg::PoliReg(int nVert, const Punto2D & centro2, float r){ //he tenido que hacer esto ya que sino esta linea:CHECK(p2.getLados() == 3); en el testPoli me da error

    if(nVert < MIN_VERT || nVert > MAX_VERT){
        N = MIN_VERT;
    }else{
        N = nVert;
    }

    if(r < MIN_RADIO || r > MAX_RADIO){
        radio = MIN_RADIO;
    }else{
        radio = r;
    }
        
    centro = centro2;

    vertices = nullptr;
    reservaMemoria(N);
    generaVertices();
}

/* Funcion copia*/
void PoliReg::copiar(const PoliReg &otro){
    this->N= otro.N;
    this->centro = otro.centro;
    this->radio = otro.radio;
    
    
    
    for(int i = 0; i < N; i++){
        vertices[i] = otro.vertices[i];
    }
    
    
}


/*
 PoliReg(const PoliReg & otro): constructor de copia.
 */
PoliReg::PoliReg(const PoliReg & otro){
    reservaMemoria(otro.N);
    this->copiar(otro);
}
/*
reservaMemoria(int tam): reserva memoria en el array vertices
para tam elementos
 */
void PoliReg::reservaMemoria(int tam) {
    vertices= new Punto2D[tam];
}

/*
 liberaMemoria(): libera la memoria ocupada por el vector vertices.
 */
void PoliReg::liberaMemoria(){
    if(vertices != nullptr){
        delete [] vertices; 
        vertices=nullptr; 
    }
    
}        

/* 
generaVertices(): utilizando el centro, el radio y N, genera
los vertices del poligono
*/
void PoliReg::generaVertices(){   
    
    float angulo=0;
    angulo = (2 * PI) / N;// en radianes
    
    Punto2D p0= centro;
    p0.setX(p0.getX() + radio);
    
    
    
    for(int i=0; i<N; i++){
        Punto2D p_aux=p0;
        
        p_aux.rotar(centro, i*angulo);
        
        vertices[i]=p_aux;
    }
}

Punto2D PoliReg::getVertice(int i) const{
    return vertices[i];
}

Punto2D PoliReg::getCentro() const{
    return centro;
}

int PoliReg::getLados() const{
    return N;
}

float PoliReg::getRadio() const{
    return radio;
}

/*
 void agregaVertice(): reconstruye el array vertices, generando un nuevo poliıgono regular con 1 vertice mas. No se permitiran´
poligonos con mas de MAX VERT vertices.
 */
void PoliReg::agregaVertice(){
    int nue_tam = this->N+1;
    if(nue_tam <= MAX_VERT){
        this->N= nue_tam;
        liberaMemoria();
        reservaMemoria(N);
        generaVertices();
    }else{
        if (DEBUG){
            cout << "Se ha alcanzado el maximo de vertices posibles" << endl;
        }
    }
    
    
}

/*
 void eliminaVertice(): reconstruye el array vertices, generando un nuevo pol´ıgono regular con 1 vertice menos. No se pue- ´
de dejar el pol´ıgono con menos de MIN VERT vertices.
 */
void PoliReg::eliminaVertice(){
    int nue_tam = N-1;
    if(nue_tam >= MIN_VERT){
        this->N= nue_tam;
        liberaMemoria();
        reservaMemoria(this->N);
        generaVertices();
    }else{
        if (DEBUG){
           cout << "Se ha alcanzado el minimo de vertices posibles" << endl;
        }
        
    }
    
}

/*
 void expande(float delta): incrementa el radio en delta
unidades y recalcula los vertices. Si el radio resultante queda fue- ´
ra del rango valido, no se hace nada.
 */
void PoliReg::expande(float delta){
    float nuevo_radio =this->radio;
    
    nuevo_radio+=delta;

    if(nuevo_radio <= MAX_RADIO && nuevo_radio>=MIN_RADIO){
        this->radio=nuevo_radio;
        reservaMemoria(this->N);
        generaVertices();
    }
}

/*
 void contrae(float delta): reduce el radio en delta unidades y recalcula los vertices. Si el radio resultante queda fuera del ´
rango valido, no se hace nada. 
 
 */
void PoliReg::contrae(float delta){
    delta = -delta;
    this->expande(delta);
}

/*
 double perimetro(): calcula y devuelve el perimetro del poligono.
 */
double PoliReg::perimetro() const{
    double lado = 2*radio*sin(PI/N); //deberemos calcular la longitud de los lados del poligono a calcular
    
    double perim = N * lado; //numero de lados * longitud de lados
    
    return perim;
}

/*
 void rotar(float rads): rota el poligono sobre su centro en
rads radianes (llama al metodo rotar de Punto2D)
 */
void PoliReg::rotar(float rads){
   
    for(int i=0; i<N; i++){ //al rotar cambia la posicion de todos los vertices.
      vertices[i].rotar(centro, rads);
    }
     
}

/*
 bool colision(const PoliReg & otro): devuelve true si
los poligonos colisionan. Para ello, debe comprobar que las correspondientes circunferencias no se intersecan (debe utilizar los respectivos 
 * centros y radios). Si no hay colision, devuelve ´ false. Debe
tener en cuenta que la sentencia p.Colision(p), debe dar false
(en otras palabras, un pol´ıgono no esta en colision consigo mismo).
 

 */

//se trata de calcular la circunferencia del poligono 
//con el centro y el radio y utilizar el metodo colision de punto2d para saber si colisionan
bool PoliReg::colision(const PoliReg & otro) const{
    
    bool respuesta= false;
    float suma_radios=this->radio + otro.radio;
    
    if(this != &otro){//coomparo direcciones de memoria para comprobar que no es el mismo poligono
        if(this->centro.distancia(otro.centro) <= suma_radios){
            respuesta=true;
        }
    }
    
    return respuesta;
}

/*
 void mover(float dx, float dy) mueve todos los puntos del
poligono (incluido el centro), llamando al metodo correspondiente de
la clase Punto2D.
 
 */


void PoliReg::mover(float dx, float dy){
    for(int i=0; i<N; i++){
        vertices[i].mover(dx,dy);
    }
    
    centro.mover(dx,dy);
}

/*
 ~PoliReg(): Destructor de la clase.
 */
PoliReg::~PoliReg(){
    liberaMemoria();
}

/*
 toString(): devuelve una cadena con los datos del pol´ıgono. El
formato esperado es el siguiente:
 */
string PoliReg::toString() const{
    string s="";
      s = "@centro " + centro.toString() +
        "\n@radio " + to_string(radio) +
        "\nvertices ";
        
    for(int i = 0; i < N; i++){
        s += vertices[i].toString() + " ";
    }

    return s;   
}

PoliReg& PoliReg::operator =(const PoliReg &rhs){ 
    
    if(this != &rhs){
        liberaMemoria();
        reservaMemoria(rhs.N);
        this->copiar(rhs);
    }
    
    
    return (*this);
            
}


ostream& operator<<(ostream &flujo, const PoliReg &otro){
    flujo << "@centro " << otro.centro << "\n@radio " << otro.radio << "\nvertices ";
        
    for(int i = 0; i < otro.N; i++){
       flujo << otro.vertices[i] << " ";
    }
    flujo << endl;
    return flujo;
}

istream& operator>>(istream &flujo, PoliReg &otro){
    string etiqueta;

    int N2;
    float radio2;
    Punto2D centro2;
  
    flujo >> etiqueta; // @centro
    flujo >> centro2;
    flujo >> etiqueta; // @radio
    flujo >> radio2;
    flujo >> etiqueta; // @puntos
    flujo >> N2;

    PoliReg aux(N2, centro2, radio2);
    
    for(int i=0;i<aux.N;i++){
        flujo >> aux.vertices[i]; // el >> de punto2D
    }
    
    otro=aux;
    return flujo;
}

bool PoliReg::operator ==(const PoliReg &rhs) const{
    bool respuesta=true;
    
    if(this->radio != rhs.getRadio() || this->N != rhs.getLados()){
        respuesta=false;
    }
    
    for(int i=0; i<N; i++){
        if(!(this->vertices[i] == rhs.vertices[i])){
            respuesta=false;    
        }
           
    }
    
    return respuesta;
}

bool PoliReg::operator <(const PoliReg &rhs) const{
    bool respuesta= false;
    
    if(this->perimetro() < rhs.perimetro()){
        respuesta = true;
    }
    
    return respuesta;
}