// lab3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <clocale>
#pragma warning(disable:4996)
#include "math.h"
#include "conio.h"
#include "locale.h"

int _tmain(int argc, _TCHAR* argv[])
{
	double a, b, x, y, z;
	setlocale(LC_CTYPE, "");
	puts("������� ������ � ����� ���������, ���");
	scanf("%lf", &a);
	scanf("%lf", &b);
	scanf("%lf", &z);
	x=a;
	while (x<=b)
	{
		if (x>10 && x<=20) 
			{
				y = pow((x+1.0), (1.0/3.0));
				printf("\nx=%0.5lf y=%0.5lf", x, y);
			}
		else if (x>=0 && x<=10 && x!=1) 
				{
					y = 10/(x-1);
					printf("\nx=%0.5lf y=%0.5lf", x, y);
				}
			  else printf("\n�=%lf �� ������ � ������� �����������", x);
		x=x+z;
	}
	getch();
	return 0;
}

