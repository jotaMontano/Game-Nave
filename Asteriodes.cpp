#include "Asteriodes.h"
#include "Nave.h"

Asteroide::Asteroide(){}

Asteroide::Asteroide(int px, int py){
	setX(px);
	setY(py);
}
void Asteroide::gotoxy(int px, int py) {
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordenadaPos;
	coordenadaPos.X = x;
	coordenadaPos.Y = y;
	SetConsoleCursorPosition(hCon, coordenadaPos);

}
void Asteroide::pintar(){
	gotoxy(getX(), getY()); printf("%c", 254);
}

void Asteroide::mover(){

	gotoxy(getX(),getY()); printf(" ");
	this->y++;
	if (this->y > 27) {
		this->x = rand() % 78;
		this->y = 2;
	}
	pintar();
}

void Asteroide::setX(int px){
	x = px;
}

void Asteroide::setY(int py){
	y = py;
}

int Asteroide::getX()
{
	return x;
}

int Asteroide::getY()
{
	return y;
}

