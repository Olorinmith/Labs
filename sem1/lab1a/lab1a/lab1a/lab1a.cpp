// lab1a.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <clocale>
#pragma warning(disable:4996)
#include "math.h"
#include "conio.h"
#include "locale.h"


int _tmain(int argc, _TCHAR* argv[])
{
	double x, y=0;
	setlocale(LC_CTYPE, "");
	puts("¬ведите х:");
	scanf("%lf", &x);
	//printf("\n%f", x);
	if (x>10 && x<=20) {
		y = pow((x+1.0), (1.0/3.0));
		printf("y=%lf", y);
	}
	else if (x>=0 && x<=10 && x!=1) {
		y = 10/(x-1);
		printf("y=%lf", y);
	}
			else puts("х не попадает в область определени€");
	
	getch();
	return 0;
}


