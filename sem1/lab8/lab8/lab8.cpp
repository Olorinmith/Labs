// lab8.cpp: определяет точку входа для консольного приложения.
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

int zapoln(int mass[10][10], int len1, int len2)
{
	for(int i=0; i<len1; i++)
	{
		for (int j=0; j<len2; j++)
		{
			scanf("%d", &mass[i][j]);
		}
	}
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

int perep(int misx[10][10], int mkon[10][10], int len)
{
	for(int i=0; i<len; i++)
	{
		for (int j=0; j<len; j++)
		{
			mkon[i][j]=misx[i][j];
		}
	}
}

int min(int a, int b)
{
	if (a>=b) return b;
	else return a;
}

int maxa(int mass[10][10], int *mi, int *mj, int len1, int len2)
{
	int max = mass[0][0];
	for(int i=0; i<len1; i++)
	{
		for (int j=0; j<len2; j++)
		{
			if (mass[i][j]>max) 
			{
				max = mass[i][j];
				*mi = i;
				*mj = j;
			}
		}
	}
	return max;
}

int krvc(int mass[10][10], int *mi, int *mj, int len1, int len2)
{
	int kol=0;
	for (int i=0; i<len1; i++)
	{
		for (int j=0; j<=i; j++)
		{
			if ((mass[i][j]) % 4 == 0) 
			{
				if (kol == 0)
				{
					*mi = i;
					*mj = j;
				}
				kol++;
			}
		}
	}
	return kol;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[10][10], c[10][10], ai, aj, k, mai, maj, maxva, kolvo, mci=-1, mcj=-1;
	setlocale(LC_CTYPE, "");
	puts("Введите размер массива А\n");
	scanf("%d", &ai);
	scanf("%d", &aj);
	puts("Введите массив А:\n");
	zapoln(a, ai, aj);
	k = min(ai, aj);
	perep(a, c, k);
	puts("\nМассив С:\n");
	vivod(c, k, k);
	int &maiuk = mai;
	int &majuk = maj;
	maxva = maxa(a, &maiuk, &majuk, ai, aj);
	printf("индексы максимального элемента в массиве А равны:%d %d\n максимум равен %d\n", mai+1, maj+1, maxva);
	int &mciuk = mci;
	int &mcjuk = mcj;
	kolvo = krvc(c, &mciuk, &mcjuk, k, k);
	if (mci != -1) 
	printf("Количество эл-в кратных 4 в массиве с равно: %d, индексы первого встреченного равны: %d %d", kolvo, mci+1, mcj+1);
	else printf("элементов кратных 4 нет");
	getch();
	return 0;
}

