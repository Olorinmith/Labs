// lab2b.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <clocale>
#pragma warning(disable:4996)
#include "math.h"
#include "conio.h"
#include "locale.h"

int _tmain(int argc, _TCHAR* argv[])
{
	double x1, x2, x;
	int n;
	setlocale(LC_CTYPE, "");
	puts("������� �1, x2 � n");
	scanf("%lf", &x1);
	scanf("%lf", &x2);
	scanf("%d", &n);
	if (n>=3)
		{
			for (int i = 3; i <= n; i++)
			{
				x = (((i - 1)*(i - 1)*(i - 1)*x2) / ((i - 2)*(i - 2)*x1));
				x1 = x2;
				x2 = x;
			}
			printf("\n�-��� �= %lf", x);
		}
	else if (n == 1) printf("\n�-��� �= %lf", x1);
		 else printf("\n�-��� �= %lf", x2);
	getch();
	return 0;
}


