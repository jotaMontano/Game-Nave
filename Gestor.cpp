#include "Gestor.h"
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <iostream>


using namespace std;

Gestor::Gestor() {}

void Gestor::crearNave(int x, int y) {
	this->nave = Nave(x, y,3,1);
}
void Gestor::crearAsteroide(int x, int y) {
	this->asteroide = Asteroide(x, y);
	for (int i = 0; i < 5; i++) {
		this->listAsteroide.push_back(new Asteroide(rand() % 76, 2));
	}
	

	
}
void Gestor::crearBalas(int x, int y){
	this->bala = Balas(x,y);
	this->listBalas.push_back(new Balas(nave.getX() + 2, nave.getY() - 1));
	this->listBalas.push_back(new Balas(nave.getX() + 2, nave.getY() - 1));
}
void Gestor::gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordenadaPos;
	coordenadaPos.X = x;
	coordenadaPos.Y = y;
	SetConsoleCursorPosition(hCon, coordenadaPos);
}

void Gestor::OcultarCursor(){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 2;
	cursor.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cursor);
}

void Gestor::deteccionDeTeclas(){
	gameOver = false;
	
	while (!gameOver) {
		gotoxy(4, 0); printf("Puntos:  %d", this->nave.getPuntos());
	this->dispararBalas();
		moverListAsteroides();
		this->nave.mover();
		detectarChoque();
		detectarChoqueBalaAsteroide();
		if (nave.verificarVidas()) {
			if (nave.verificarCorazones()) {
				nave.borrar();
				gameOver = true;
			}
		}
		Sleep(30);
		
	}
}

void Gestor::dispararBalas() {
	if (_kbhit()) {
		char tecla = _getch();
		if (tecla == 'a') {
			crearBalas(nave.getX() + 2, nave.getY() - 1);

		}
	}

	for (this->i = this->listBalas.begin(); this->i != this->listBalas.end();) {
		(*i)->mover();
		if ((*i)->limite()) {
			(*i)->gotoxy((*i)->getX(), (*i)->getY()); printf(" ");
			delete(*i);
			i = listBalas.erase(i);
			
		}
		else {
			i++;
		}
	

	}
}



void Gestor::detectarChoqueBalaAsteroide() {
	
	i = listBalas.begin();

	j = listAsteroide.begin();

	for (j = listAsteroide.begin(); j != listAsteroide.end();) {
		for (i = listBalas.begin(); i != listBalas.end();) {
		
			if ((*i)->getX() == (*j)->getX() && (*i)->getY() +1 == (*j)->getY() || (*i)->getY() == (*j)->getY() && (*i)->getX() == (*j)->getX()) {
			(*i)->gotoxy((*i)->getX(), (*i)->getY()); printf("  ");
				delete(*i);
				i = listBalas.erase(i);

				(*j)->gotoxy((*j)->getX(), (*j)->getY()); printf("  ");
				delete(*j);
				j = listAsteroide.erase(j);
				this->listAsteroide.push_back(new Asteroide(rand() % 76, 2));
				this->nave.setPuntos(5);
				i = listBalas.end();
				j = listAsteroide.end();
			}
			else {
				i++;
			}
		}
		if (j != listAsteroide.end()) {
			j++;
		}
			
	}

}
void Gestor::detectarChoque(){	
	j = listAsteroide.begin();
	while (j != listAsteroide.end()) {
		if ((*j)->getX() >= nave.getX() && (*j)->getX() < nave.getX() + 5 && (*j)->getY() >= nave.getY() && (*j)->getY() <= nave.getY() + 2) {
			nave.quitarCorazones();
			nave.pintar();
			nave.pintarCorazones();
			int x, y;
			x = rand() % 77;
			y = 2;
			(*j)->setX(x);
			(*j)->setY(y);

		}

		j++;
	}
	
}

/* Agregar jugador */
void Gestor::agregarJugador(string pnombre) {
	Jugador jugador(pnombre);
	listaJugadores.agregarJugador(jugador);
}

string Gestor::mostrarJugadores() {

	return listaJugadores.mostrarJugadores();
}

string Gestor::buscarJugador(string pcodigo)
{
	return listaJugadores.buscarInfoDelJugador(pcodigo);
}


bool Gestor::validarSiHayJugadores()
{
	return listaJugadores.ListjugadoresVacio();
}

Jugador Gestor::encontrarObjJugador(){
	return Jugador();
}

bool Gestor::getGameOver()
{
	return gameOver;
}

void Gestor::moverListAsteroides(){
	j = listAsteroide.begin();

	while (j != listAsteroide.end()) {
		(*j)->mover();
		j++;
	}
}






