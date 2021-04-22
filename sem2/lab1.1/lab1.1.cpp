// lab1.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "stdio.h"
#include "locale.h"
#include "conio.h"

struct stud{
	char fam[20];
	char gryp[20];
	int mark[5];
};

void zap(stud &t)
{
	puts("Введите фамилию:");
	gets_s(t.fam);
	puts("Введите группу:");
	gets_s(t.gryp);
	puts("Введите 5 оценок:");
	for(int i = 0; i < 5; i++)
	{
		scanf_s("%d", &t.mark[i]);
	}
}

void vivod(stud t)
{
	printf("Фамилия: %s", &t.fam);
	printf("Группа: %s\n", &t.gryp);
	printf("Оценки: ");
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", &t.mark[i]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	int k;
	puts("Введите количество студентов:");
	scanf_s("%d", &k);
	stud *mas = new stud [k];
	for (int i = 0; i < k; i++)
	{
		zap(mas[i]);
	}
	for (int i = 0; i < k; i++)
	{
		printf("Студент %d:\n", i);
		vivod(mas[i]);
	}
	_getch();
	return 0;
}

