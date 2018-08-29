#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <iostream>
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#include "Gestor.h"


Gestor gestor;
void iniciarJuego();
void initGestores() {
	gestor = Gestor::Gestor();
	
}

int main(int argc, char** argv) {
	gestor.OcultarCursor();
	iniciarJuego();
	void mostarMenu();
	string leerOp();
	bool ejecutarMenu(string opcion);

	string opcion;
	bool noSalir = true;

	while (noSalir) {
		mostarMenu();
		opcion = leerOp();
		noSalir = ejecutarMenu(opcion);
	}
	getchar();
	return 0;
}

void mostarMenu() {

	cout << "**    Menu    **" << endl;
	cout << "1. Agregar jugador" << endl;
	cout << "2. Mostrar jugador" << endl;
	cout << "3. Escoger jugador" << endl;
	cout << "4. Iniciar juego" << endl;
	cout << "Seleccione una opcion" << endl;
}


string leerOp() {
	string opcion;
	cin >> opcion;
	return opcion;
}

bool ejecutarMenu(string opcion) {
	void agregarJugador();
	void mostrarJugadores();
	void escogerJugador();
	void iniciarJuego();
	void pintarLimites();
	if (opcion == "1") {
		agregarJugador();
	}
	else if (opcion == "2") {
		mostrarJugadores();

	}
	else if (opcion == "3") {
		escogerJugador();
	}
	else if (opcion == "4") {
		iniciarJuego();
	}
	else if (opcion == "5") {

	}
	else if (opcion == "6") {

	}
	else if (opcion == "7") {

	}
	else if (opcion == "8") {

	}
	else if (opcion == "9") {

	}
	else if (opcion == "10") {

	}
	else if (opcion == "0") {
		return false;
	}
	else {
		cout << "Opcion invalida" << "\n" << endl;
	}
	return true;
}
void agregarJugador() {
	string nombre;
	cout << "Ingrese el nombre/ o apodo del jugador" << endl;
	cin >> nombre;
	gestor.agregarJugador(nombre);
	cout << "Se ingreso correctamente el jugador" << endl;
}
void mostrarJugadores() {
	if (!gestor.validarSiHayJugadores()) {
		cout << gestor.mostrarJugadores() << endl;
	}
	else {
		cout << "No se encuentran registrados jugadores \n" << endl;
	}

}
void escogerJugador() {
	string codigo;
	if (!gestor.validarSiHayJugadores()) {
		cout << gestor.mostrarJugadores() << endl;
		cout << "\n Ingrese el codigo del jugador " << endl;
		cin >> codigo;
		cout << gestor.buscarJugador(codigo) << endl;
	}
	else {
		cout << "No se encuentran registrados jugadores\n" << endl;
	}

}
void pintarLimites() {
	for (int i = 1; i < 78; i++) {
		gestor.gotoxy(i, 1);
		printf("%C", 205);
		gestor.gotoxy(i, 28);
		printf("%C", 205);
	}
	for (int i = 2; i < 29; i++) {
		gestor.gotoxy(0, i);
		printf("%C", 186);
		gestor.gotoxy(78, i);
		printf("%C", 186);
	}
	gestor.gotoxy(0,1 );
	printf("%C", 201);
	gestor.gotoxy(0, 28);
	printf("%C", 200);
	gestor.gotoxy(78, 1);
	printf("%C", 187);
	gestor.gotoxy(78, 28);
	printf("%C", 188);

}
void iniciarJuego() {
	system("cls");
	gestor.OcultarCursor();
	int x, y,postAster = 10,postAsterH = 4;
	
	system("cls");
	pintarLimites();
	gestor.crearNave(25, 25);
	gestor.crearAsteroide(postAster, postAsterH);
	gestor.deteccionDeTeclas();
	if (gestor.getGameOver()) {
		cout << "Game over  " << endl;
		Sleep(2000);
		system("cls");
	}
	
}


