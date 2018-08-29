#include "Balas.h"

Balas::Balas() {}

Balas::Balas(int px, int py) {
	setX(px);
	setY(py);

}
void Balas::gotoxy(int x, int y) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordenadaPos;
	coordenadaPos.X = x;
	coordenadaPos.Y = y;
	SetConsoleCursorPosition(hCon, coordenadaPos);

}

void Balas::setX(int px) {
	x = px;
}

void Balas::setY(int py) {
	y = py;
}

int Balas::getX()
{
	return x;
}

int Balas::getY()
{
	return y;
}
void Balas::mover() {
	gotoxy(x, y); printf(" ");
	if (y > 2) y--;
	gotoxy(x, y); printf("*");
}

bool Balas::limite(){
	if (this->getY() <= 2 ) {
		return true;
	}
	return false;
}
