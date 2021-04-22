// lab7.cpp: определяет точку входа для консольного приложения.
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

int zapoln(int m, int n, int mass[10][10], int len1, int len2)
{
	for(int i=0; i<len1; i++)
	{
		for (int j=0; j<len2; j++)
		{
			mass[i][j] = rand()%(n-m+1)+m;
		}
	}
	return mass[10][10];
}


void vivod(int m[10][10], int len1, int len2)
{
	for (int i=0; i<len1; i++)
	{
		for (int j=0; j<len2; j++)
		{
			printf("%4d", m[i][j]);
		}
		printf("\n");
	}
}

int zad1(int m[10][10], int len)
{
	int kol=0;
	for (int i=0; i<len; i++)
	{
		for (int j=i; j<len; j++)
		{
			if (m[i][j] > 0) kol++;
		}
	}
	return kol;
}
double zad2(int m[10][10], int len)
{
	int kol=0;
	int sum = 0;
	double sr;
	for (int i=0; i<len; i++)
	{
		for (int j=0; j<len; j++)
		{
			if (i == len-1-j) 
			{
				sum = sum + m[i][j];
				kol++;
			}
		}
	}
	sr = (sum*1.0)/(kol*1.0);
	return sr;
}

int min(int a, int b)
{
	if (a>=b) return b;
	else return a;
}

int zad3(int m[10][10], int x, int y, int m1[10][10], int m2[10][10])
{
	for (int i=0; i<x; i++)
	{
		for (int j=0; j<y; j++)
		{
			m[i][j] = 2*m1[i][j]+m2[i][j];
		}
	}
	return m[10][10];
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[10][10], b[10][10], c[10][10], n1, n2, m2, kol, x, y;
	double sr;
	setlocale(LC_CTYPE, "");
	puts("Введите размер массива А:");
	scanf("%d", &n1);
	puts("Введите размер массива B:");
	scanf("%d", &n2);
	scanf("%d", &m2);
	srand(time(NULL));
	zapoln(-5, 5, a, n1, n1);
	zapoln(0, 10, b, n2, m2);
	vivod(a, n1, n1);
	puts("\n");
	vivod(b, n2, m2);
	//Задание 1. Колво полож эл-в в масс А выше и на гл диаг
	kol = zad1(a, n1);
	printf("Количество положительных элементов на и выше главной диагонали массива А: %d", kol);
	//Задание 2. Ср ар эл-в побочной диагонали в масс А
	sr = zad2(a, n1);
	printf("\nСреднее арифметическое побочной диагонали массива А: %lf", sr);
	//Задание 3. Вывести массив С
	puts("\n");
	x = min(n1, n2);
	y = min(n1, m2);
	zad3(c, x, y, a, b);
	vivod(c, x, y);
	getch();
	return 0;
}

