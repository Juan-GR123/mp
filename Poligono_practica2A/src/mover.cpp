/*
Metodologías de la Programación - David Pelta
Fichero de ejemplo para comprender la lectura de teclas en Raylib

// asumiendo que libraylib.a y raylib.h están en la mismatch
// carpeta que este fichero: 

g++ mover.cpp -I. -lraylib -L. -o mover
*/

#include "raylib.h"
#include <string>

using namespace std;

struct Par {
	float x, y;
};

struct Bola{
	Par pos;
	Par vel;
	int radio = 10;
};

void mover(Bola & b){
	b.pos.x += b.vel.x;
	b.pos.y += b.vel.y;
}

void rebotar(Bola & b){
	if ((b.pos.x >= (GetScreenWidth() - b.radio)) || (b.pos.x <= b.radio))
		b.vel.x *= -1.1;
	if ((b.pos.y >= (GetScreenHeight() - b.radio)) || (b.pos.y <= b.radio))
		b.vel.y *= -1.1;
}

void wrap(Bola & b){
	// salida por izquierda / derecha
	if (b.pos.x >= (GetScreenWidth() - b.radio))
		b.pos.x = b.radio * 1.1;

	if (b.pos.x <= b.radio)
		b.pos.x = GetScreenWidth() - (b.radio * 1.1);
	
	// salida por abajo o arriba
	if (b.pos.y >= (GetScreenHeight() - b.radio))
		b.pos.y = b.radio * 1.1;
	
	if (b.pos.y <= b.radio)
		b.pos.y = GetScreenHeight() - (b.radio * 1.1);
}

void dibujar(const Bola & b){
	DrawCircle(b.pos.x, b.pos.y, b.radio, MAROON);
	string s = "Posición: (" + to_string((int)b.pos.x) + ", " + to_string((int)b.pos.y) + ")";
	DrawText(s.c_str(), 10, 20, 25, BLACK);

}
int main(void)
{
	// Initialization
	//---------------------------------------------------------
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Mover bloque");

	Par centro = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
	
	// valores para fijar velocidad
	Par UP = {0.0, -6.0};
	Par DOWN = {0.0, 6.0};
	Par LEFT = {-6.0, 0.0};
	Par RIGHT = {6.0, 0.0};
	Par STOP = {0.0f, 0.0f};
	
	// el objeto a mover
	Bola disco = {centro, STOP, 15};
	
	SetTargetFPS(20);
	Par aux;
	bool pause;
	while (!WindowShouldClose()) {
		// actualizar estado de los objetos 
		pause = false;
		if (IsKeyPressed(KEY_UP))
			aux = UP;
		else if (IsKeyPressed(KEY_DOWN))
			aux = DOWN;
		else if (IsKeyPressed(KEY_LEFT))
			aux = LEFT;
		else if (IsKeyPressed(KEY_RIGHT))
			aux = RIGHT;
		else if (IsKeyPressed(KEY_SPACE))
			aux = STOP;
		else
			pause = true; // si no se ha pulsado ninguna tecla

		// OPCION 1:
		//choque con los bordes
		//rebotar(disco);
		
		// OPCION 2:
		//mundo circular
		wrap(disco);
		
		// cambiar la velocidad si se pulsó alguna tecla
		
		if (!pause){
			disco.vel = aux;
		}
		
		mover(disco);
		
		//-----------------------------------------------------
		// Dibujar
		//-----------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		dibujar(disco);
		EndDrawing();
		//-----------------------------------------------------
	}

	CloseWindow();
	return 0;
}
