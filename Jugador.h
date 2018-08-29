#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <string>
using namespace std;

class Jugador {
public:
	Jugador();
	Jugador(string pnombre);
	string getCodigo();
	void setCodigo();
	string getNombre();
	void setNombre(string pnombre);
	string toString();

private:
	static int autoGenerateListaJugador;
	string codigo;
	string nombre;
};
#endif // !JUGADORES_H

