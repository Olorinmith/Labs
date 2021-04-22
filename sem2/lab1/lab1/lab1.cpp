// lab1.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "stdio.h"
#include "locale.h"
#include "conio.h"

struct sp{
	int inn;
	char fam[20];

};

void zap(sp &t)
{
	puts("¬ведите пол€:");
	scanf_s("%d", &t.inn);
	getchar();
	gets_s(t.fam);
}

void vivod(sp t)
{
	printf("inn: %d, fam: %s\n", t.inn, t.fam);
}


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	sp t, t2, a[3];
	int n, k;
	char s[20];
	/*puts("¬ведите значение пол€:");
	scanf_s("%d", &t.inn);
	getchar();
	gets_s(t.fam);
	printf("inn: %d, fam: %s", t.inn, t.fam);
	puts("\n¬ведите значение пол€ 2:");
	scanf_s("%d", &t2.inn);
	getchar();
	gets_s(t2.fam);
	printf("inn: %d, fam: %s", t2.inn, t2.fam);
	puts("\n«аполните три элемента:");
	for(int i = 0; i < 3; i++)
	{
		printf("¬ведите пол€ элемента %d:\n", i+1);
		scanf_s("%d", &a[i].inn);
		getchar();
		gets_s(a[i].fam);
	}
	puts("¬веденные элементы:");
	for(int i = 0; i < 3; i++)
	{
		printf("inn: %d, fam: %s\n", a[i].inn, a[i].fam);
	}*/
	puts("¬ведите количество людей:");
	scanf_s("%d", &n);
	sp *mas = new sp [n];
	for (int i = 0; i < n; i++)
	{
		zap(mas[i]);
	}
	puts("¬веденный список:");
	for (int i = 0; i < n; i++)
	{
		vivod(mas[i]);
	}
	puts("¬ведите фамилию человека инн которого надо найти:");
	gets_s(s);
	for (int i = 0; i < n; i++)
	{
		if(strcmp(mas[i].fam, s) == 0)
		{
			printf("inn этого человека: %d", mas[i].inn);
			break;
		}
	}
	puts("\n¬ведите инн, найти людей у которых инн больше введенного:");
	scanf_s("%d", &k);
	puts("fam этого человека:");
	for (int i = 0; i < n; i++)
	{
		if(mas[i].inn > k)
		{
			printf("%s\n", mas[i].fam);
		}
	}
	//sort
	int temp1;
	int fl;
	char temps[20];
	do
	{
		fl = 0;
		for(int i = 1; i < n; i++)
		{
			if(mas[i].inn < mas[i-1].inn)
			{
				temp1 = mas[i].inn;
				mas[i].inn = mas[i-1].inn;
				mas[i-1].inn = temp1;

				strcpy_s(temps, mas[i].fam);
				strcpy_s(mas[i].fam, mas[i-1].fam);
				strcpy_s(mas[i-1].fam, temps);
				fl = 1;
			}
		}
	}
	while(fl == 1);
	puts("ќтсортированный список:");
	for (int i = 0; i < n; i++)
	{
		vivod(mas[i]);
	}
	_getch();
	return 0;
}

