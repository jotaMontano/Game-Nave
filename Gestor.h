#ifndef GESTOR_H
#define GESTOR_H
#include "ListaJugadores.h"
#include "ListaPuntos.h"
#include "Nave.h"
#include "Balas.h"
#include "list"
#include <time.h>
#include "Asteriodes.h"
#include <iostream>
#include <string> 
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
class Gestor {
public:
	Gestor();
	void crearNave(int x, int y);
	void crearAsteroide(int x, int y);
	void crearBalas(int x, int y);
	void gotoxy(int x, int y);
	void OcultarCursor();
	void deteccionDeTeclas();
	void detectarChoqueBalaAsteroide();
	void dispararBalas();
	void agregarJugador(string pnombre);
	string mostrarJugadores();
	string buscarJugador(string pcodigo);
	bool validarSiHayJugadores();
	Jugador encontrarObjJugador();
	bool getGameOver();
	void moverListAsteroides();
	
	void detectarChoque();
private:
	ListaJugadores listaJugadores;
	Nave nave;
	Asteroide asteroide;
	Balas bala;
	list<Balas*> listBalas;
	list<Balas*>::iterator i;
	list<Asteroide*> listAsteroide;
	list<Asteroide*>::iterator j;
	Jugador jugador;
	bool gameOver = false;
};
#endif // !GESTOR_H
