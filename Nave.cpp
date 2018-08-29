#include "Nave.h"

Nave::Nave(){}

Nave::Nave(int px, int py,int pcorazon,int pvidas) {
	setX(px);
	setY(py);
	setCorazones(pcorazon);
	setVidas(pvidas);
	pintar();

}
void Nave::gotoxy(int x,int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordenadaPos;
	coordenadaPos.X = x;
	coordenadaPos.Y = y;
	SetConsoleCursorPosition(hCon, coordenadaPos);
	
}

void Nave::setX(int px){
	x = px;
}

void Nave::setY(int py){
	y = py;
}

int Nave::getX()
{
	return x;
}

int Nave::getY()
{
	return y;
}
void Nave::setCorazones(int pcorazon){
	corazones = pcorazon;
}
int Nave::getCorazones(){
	return corazones;
}
void Nave::setVidas(int cantVidas){
	vidas = cantVidas;
}
int Nave::getVidas()
{
	return vidas;
}
void Nave::pintar() {
	gotoxy(this->x,  this->y); printf(" %C", 30);
	gotoxy(this->x,  this->y + 1); printf(" %C%C%C", 40, 207, 41);
	gotoxy(this->x,  this->y + 2); printf(" %C%C %C%C", 30, 190, 190, 30);
}

void Nave::borrar()
{
	gotoxy(x, y);	  printf("       ");
	gotoxy(x, y + 1); printf("       ");
	gotoxy(x, y + 2); printf("       ");
}
void Nave::mover() {
	int px,py;
	pintarCorazones();
	if (_kbhit()) {
		char tecla = _getch();
		borrar();
		if (tecla == IZQUIERDA && getX() >1 )x--;
		px = getX();
		setX(px--);
		if (tecla == DERECHA && getX() < 71)x++;
		px = getX();
		setX(px++);
		if (tecla == ARRIBA && getY() > 2) y--;
		py = getY();
		setY(py--);
		if (tecla == ABAJO && getY() + 2 < 27) y++;
		py = getY();
		setY(py++);
		if (tecla == 'e') quitarCorazones();
		
		pintar();
		morir();
	}
}
void Nave::pintarCorazones() {
	gotoxy(50, 0); printf("Vidas %d", getVidas());
	gotoxy(64, 0); printf("Salud");
	gotoxy(70, 0); printf("   ");
	for (int i = 0; i < getCorazones(); i++) {
		gotoxy(70 + i, 0); 
		printf("%c",3);
		
	}
}
void Nave::morir(){
	if (getCorazones() == 0) {
		borrar();
		gotoxy(x, y);	  printf("   **  ");
		gotoxy(x, y + 1); printf("  **** ");
		gotoxy(x, y + 2); printf("   **  ");
		Sleep(200);
		borrar();

		gotoxy(x, y);	  printf(" * ** *");
		gotoxy(x, y + 1); printf("  **** ");
		gotoxy(x, y + 2); printf(" * ** *");
		Sleep(200);
		borrar();

		quitarVida();
		setCorazones(3);
		pintarCorazones();
		pintar();
	}
}
int Nave::getPuntos()
{
	return puntos;
}
boolean Nave::verificarVidas(){
	if (vidas == 0) {
		return true;
	}
	return false;
}
boolean Nave::verificarCorazones(){
	if (corazones == 0) {
		return true;
	}
	return false;
}
void Nave::setPuntos(int ppunto){
	puntos = puntos + ppunto;
}
void Nave::quitarCorazones() {
	corazones--;
}
void Nave::quitarVida() {
	vidas--;
}