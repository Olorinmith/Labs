// lab2test.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <clocale>
#pragma warning(disable:4996)
#include "math.h"
#include "conio.h"
#include "locale.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	int n;
	double summ=0, x;
	puts("¬ведите n и x");
	scanf("%d", &n);
	scanf("%lf", &x);
	for(int i=1; i<=n; i++){
		summ = summ + ((pow((-1.0), i)*pow(x, (2*i-1)))/(2*i-1));
	}
	printf("\n%lf", summ);
	getch();
	return 0;
}

