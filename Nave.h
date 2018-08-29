#ifndef NAVE_H
#define NAVE_H
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<list>
#include <iostream>
#include <string>
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
using namespace std;

class Nave{
public:
	Nave();
	Nave(int px,int py, int pcorazon,int vidas);
	void pintar();
	void borrar();
	void mover();
	void pintarCorazones();
	void gotoxy(int x,int y);
	void setX(int px);
	void setY(int py);
	int getX();
	int getY();
	void setCorazones(int cantCorazones);
	int getCorazones();
	void setVidas(int cantVidas);
	int getVidas();
	void quitarVida();
	void quitarCorazones();
	void morir();
	int getPuntos();
	boolean verificarVidas();
	boolean verificarCorazones();
	void setPuntos(int ppunto);
private:
	int x, y;
	int corazones = 3;
	int vidas = 1;
	int puntos = 0;
};
#endif // !NAVE_H
