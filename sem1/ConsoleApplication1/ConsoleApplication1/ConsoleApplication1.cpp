// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "math.h"
#include <clocale>
#include "conio.h"
#include "locale.h"
#pragma warning (disable:4996)


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	double eps, r, sum=0, fact=1;
	int i;
	puts("Введите точность:");
	scanf("%lf", &eps);
	while (fabs(r)>=eps)
	{
		r=(i/(fact+i*i));
		fact=fact*i;
		sum=sum+r;
	}
	printf("Сумма ряда равна: %lf", sum);
	printf("\nПоследнее слагаемое:%lf", r);
	getch();
	return 0;
}