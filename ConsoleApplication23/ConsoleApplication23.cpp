#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;

const int xInicio = 4;
const int yInicio = 3;
const int niveles = 4;

const int separacionX = 6;
const int separacionY = 2;

void goToXY(int x, int y) {
	Console::SetCursorPosition(x, y);
}

void changeTextColorToYellow() {
	Console::ForegroundColor = ConsoleColor::Yellow;
}
void resetTextColor() {
	Console::ResetColor();
}

void dibujarArroba(int x, int y) {
	goToXY(x, y);
	changeTextColorToYellow();
	cout << "@";
	resetTextColor();
}

void borrarArroba(int x, int y) {
	goToXY(x, y);
	cout << " ";
}

void moverDerecha(int x, int y, int xFinal) {
	while (x < xFinal) {
		borrarArroba(x, y);
		x += 1;
		dibujarArroba(x, y);
		_sleep(15);
	}
}
void moverAbajo(int x, int y, int yFinal) {
	while (y < yFinal) {
		borrarArroba(x, y);
		y += 1;
		dibujarArroba(x, y);
		_sleep(30);
	}
}

void moverIzquierda(int x, int y, int xFinal) {
	while (x > xFinal) {
		borrarArroba(x, y);
		x -= 1;
		dibujarArroba(x, y);
		_sleep(15);
	}
}

void moverArriba(int x, int y, int yFinal) {
	while (y > yFinal) {
		borrarArroba(x, y);
		y -= 1;
		dibujarArroba(x, y);
		_sleep(30);
	}
}

void movimientoEspiral(int niveles) {

	int x = xInicio;
	int y = yInicio;

	int derecha = x + 2 * niveles * separacionX;
	int abajo = y + 2 * niveles * separacionY;
	int izquierda = xInicio;
	int arriba = yInicio;

	for (int nivel = 1; nivel <= niveles; nivel++)
	{
		moverDerecha(x, y, derecha);
		x = derecha;
		moverAbajo(x, y, abajo);
		y = abajo;
		moverIzquierda(x, y, izquierda);
		x = izquierda;
		moverArriba(x, y, arriba + separacionY);
		y = arriba + separacionY;

		izquierda += separacionX;
		derecha -= separacionX;
		arriba += separacionY;
		abajo -= separacionY;
	}
}


int main(){
	Console::CursorVisible = false;

	dibujarArroba(xInicio, yInicio);

	while (1) {
		if (Console::KeyAvailable) {
			ConsoleKeyInfo tecla = Console::ReadKey(true);
			if (tecla.Key == ConsoleKey::D) {
				movimientoEspiral(niveles);
			}
		}
	}

	cin.get();
	cin.ignore();

	return 0;
}
