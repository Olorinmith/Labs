// lab12.cpp: определяет точку входа для консольного приложения.
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
#include "string.h"

void vivodmas(double **a, int n)
{
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j< n; j++)
		{
			printf("%7.3lf", a[i][j]);
		}
		printf("\n");
	}
}

void indpoisk(double **a, int n, double k, int &ai, int &aj)
{
	int fl =0;
	ai = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j<n; j++)
		{
			if ((a[i][j] == k) && (fl== 0))
			{
				ai = i;
				aj = j;
				fl = 1;
			}
		}
	}
}

void poisk_pervogo_a(char *c, int lenc, int &ci)
{
	int fl = 1;
	for (int i =0; i<lenc; i++)
	{
		if ((c[i] == 'a')&&(fl == 1))
		{
			ci = i;
			fl =0;
		}
	}
}

void zamena(double **a, int ci)
{
	a[ci][ci] = 0;
}

int kolvo_slov(char *str)
{
	int k=0;
	char *temp = strtok(str, " ");
	while (temp != NULL)
	{
		k++;
		temp = strtok(NULL, " ");
	}
	return k;
}

/*void sort(double **a, int n, int k)
{
	double temp;
	int fl=1;
	int j= 0;
	while ((fl==1)&&(j<=n-1))
	{
		fl = 0;
		for(int i = 0; i<n - j
		if(a[k][j]>a[k][j+1])
			{
				temp = a[k][j];
				a[k][j]= a[k][j+1];
				a[k][j+1] = temp;
			}
		}
	}
}*/

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *f1, *f2;
	int n, ai, aj, lenc, ci, k;
	double num;
	char str[100];
	setlocale(LC_CTYPE, "");
	f1 = fopen("f1.txt", "r");
	if (f1 == 0)
	{
		puts("Ошибка открытия файла");
		getch();
		return 1;
	}
	fscanf(f1, "%d", &n);
	double **a = new double *[n];
	for (int i =0; i<n; i++)
	{
		a[i] = new double [n];
	}
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j< n; j++)
		{
		fscanf(f1, "%lf", &a[i][j]);
		}
	}
	vivodmas(a, n);
	puts("Введите число которое надо найти:");
	scanf("%lf", &num);
	indpoisk(a, n, num, ai, aj);
	if (ai != -1)
	{
		printf("Индексы введенного с клавиатуры элемента равны: %d, %d", ai+1, aj+1);
	}
	else printf("Нет такого числа");
	puts("\nВведите размерность массива С:");
	scanf("%d", &lenc);
	getchar();
	char *c = new char [lenc];
	puts("Введите строку С:");
	gets(c);
	poisk_pervogo_a(c, lenc, ci);
	zamena(a, ci);
	vivodmas(a, n);
	puts("Введите строку не более 100 символов:");
	gets(str);
	k = kolvo_slov(str);
	printf("Количество слов равно: %d", k);
	//sort(a, n, k);
	f2 = fopen("f2.txt", "w");
	if (f2 == 0)
	{
		puts("Ошибка открытия файла");
		getch();
		return 1;
	}
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j< n; j++)
		{
		fprintf(f2, "%7.3lf", a[i][j]);
		}
		fprintf(f2, "\n");
	}
	getch();
	return 0;
}

