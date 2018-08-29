#ifndef ASTEROIDE_H
#define ASTEROIDE_H
#include <iostream>
#include <string>
#include<stdio.h>
#include<Windows.h>
#include<cstdlib>
#include<conio.h>
using namespace std;

class Asteroide {
public:
	Asteroide();
	Asteroide(int px,int py);
	void pintar();
	void mover();
	void setX(int px);
	void setY(int py);
	void gotoxy(int px, int py);
	int getX(); 
	int getY();

private:
	int x, y;
	
};
#endif // !NAVE_H
#pragma once
