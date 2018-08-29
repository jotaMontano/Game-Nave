#ifndef BALAS_H
#define BALAS_H
#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include <iostream>
#include <string>

using namespace std;

class Balas{
public:
	Balas();
	Balas(int px, int py);
	void gotoxy(int x, int y);
	void setX(int px);
	void setY(int py);
	int getX();
	int getY();
	void mover();
	bool limite();

private:
	int x, y;
};
#endif // !BALAS_H
