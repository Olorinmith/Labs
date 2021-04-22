// lab5.cpp: определяет точку входа для консольного приложения.
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
	double a[10][10], max, sum=0, temp, tsum=0, summax=0;
	int n, m, z, n1, m1, n2, m2, maxj;
	puts("Введите количество строк и количество столбцов не превышающее 10:");
	do 
	{
		scanf("%d", &n);
		scanf("%d", &m);
		if (n>10 || m>10) puts("\nразмер не должен превышать 10");
	}
	while (n>10 || m>10);
	//ввод массива
	puts("Введите массив:");
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	//вывод массива
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%7.3lf", a[i][j]);
		}
		printf("\n");
	}
	//задание 1, найти максимальный элемент массива
	max=a[0][0];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (a[i][j] > max) max = a[i][j];
		}
	}
	printf("максимальный элемент массива равен: %lf", max);
	//задание 2, найти среднее арифметическое строки введ с клав
	puts("\nВведите номер строки:");
	scanf("%d", &z);
	for (int j=0; j<m; j++)
	{
		sum = sum + a[z-1][j];
	}
	printf("\nСреднее арифметическое строки %d равно: %lf", z, sum/m);
	//задание 3, поменять местами элементы, индексы введены с клавиатуры
	puts("\nВведите индексы первого элемента:");
	scanf("%d", &n1);
	scanf("%d", &m1);
	puts("\nВведите индексы второго элемента:");
	scanf("%d", &n2);
	scanf("%d", &m2);
	temp = a[n1-1][m1-1];
	a[n1-1][m1-1] = a[n2-1][m2-1];
	a[n2-1][m2-1] = temp;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%7.3lf", a[i][j]);
		}
		printf("\n");
	}
	//Задание 4, найти номер столбца в котором наибольшая сумма элементов

	for (int j=0; j<m; j++)
	{
		summax = summax +a[1][j];
	}
	maxj = 0;
	for (int j=0; j<m; j++)
	{
		for (int i=0; i<n; i++)
		{
			tsum = tsum + a[i][j];
		}
		if (summax < tsum) maxj = j;
	}
	printf("\nномер столбца в котором сумма элементов максимальна равен: %d", maxj+1);
	getch();
	return 0;
}

