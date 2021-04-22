// lab1b.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <clocale>
#pragma warning(disable:4996)
#include "math.h"
#include "conio.h"
#include "locale.h"


int _tmain(int argc, _TCHAR* argv[])
{
	double x1, y1, x2, y2, x3, y3;
	setlocale(LC_CTYPE, "");
	puts("Введите х1, у1:");
	scanf("%lf", &x1);
	scanf("%lf", &y1);
	if ((x1<=0) && ((x1>=-2.0 && y1<=(0.5*x1+1)) && (x1>=-2.0 && y1>=(-0.5*x1-1)))) puts("точка принадлежит области");
	else if ((x1>=0) && (pow(x1, 2.0)+pow(y1, 2.0) <= 1)) puts("точка принадлежит области");
	else puts("точка не принадлежит области");

	puts("Введите х2, у2:");
	scanf("%lf", &x2);
	scanf("%lf", &y2);
	if ((x2<=0) && ((x2>=-2.0 && y2<=(0.5*x2+1)) && (x2>=-2.0 && y2>=(-0.5*x2-1)))) puts("точка принадлежит области");
	else if ((x2>=0) && (pow(x2, 2.0)+pow(y2, 2.0) <= 1)) puts("точка принадлежит области");
	else puts("точка не принадлежит области");

	puts("Введите х3, у3:");
	scanf("%lf", &x3);
	scanf("%lf", &y3);
	if ((x3<=0) && ((x3>=-2.0 && y3<=(0.5*x3+1)) && (x3>=-2.0 && y3>=(-0.5*x3-1)))) puts("точка принадлежит области");
	else if ((x3>=0) && (pow(x3, 2.0)+pow(y3, 2.0) <= 1)) puts("точка принадлежит области");
	else puts("точка не принадлежит области");
	getch();
	return 0;
}

