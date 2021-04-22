// lab10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <clocale>
#pragma warning(disable:4996)
#include "math.h"
#include "conio.h"
#include "locale.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void vivod(char s[], int len)
{
	puts("");
	for(int i=0; i<len; i++)
	{
		printf("%c", s[i]);
	}
	puts("");
}

void vivoddv(int **k, int len1, int len2)
{
	for(int i = 0; i<len1; i++)
	{
		for(int j = 0; j<len1; j++)
		{
			printf("%4d", k[i][j]);
		}
		printf("\n");
	}
}

int kolvox(char s[], int len, int &ind)
{
	int fl = 0, count = 0;
	for(int i=0; i<len; i++)
	{
		if (s[i] == 'x')
		{
			if (fl==0) 
			{
					ind = i;
					fl =1;
			}
			count++;
		}
	}
	return count;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char a[6], b[6];
	int len, n, n1, m, m1;
	srand(time(NULL));
	setlocale(LC_CTYPE, "");
	puts("Введите строку а:");
	for(int i=0; i<6; i++)
	{
		scanf("%c", &a[i]);
		getchar();
	}
	vivod(a, 6);
	puts("");
	puts("Введите массив b:");
	for(int i=0; i<6; i++)
	{
		b[i] = getchar();
		getchar();
	}
	vivod(b, 6);
	puts("Введите длину строки с:");
	scanf("%d", &len);
	char *c = new char [len];
	for (int i = 0; i<len; i++)
	{
		c[i] = getch();
	}
	vivod(c, len);
	n = kolvox(a, 6, n1);
	m = kolvox(b, 6, m1);

	if ((n != 0)&&(m != 0))
	{
		int **k = new int* [n];
		for (int i=0; i<n; i++)
		{
			k[i] = new int[m];
		}

		for(int i = 0;i<n;i++)
		{
			for(int j = 0; j<m;j++)
			{
				k[i][j] = rand()%11;
			}
		}

		vivoddv(k, n, m);
		puts("");
		k[n1][m1] = 0;
		vivoddv(k, n, m);
		puts("");
	}
	else puts("Нельзя создать такой массив");
	getch();
	return 0;
}

