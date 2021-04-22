// lab1+.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "stdio.h"
#include "locale.h"
#include "conio.h"
#pragma warning(disable:4996)

struct stud{
	char fam[20];
	char gryp[20];
	int mark[5];
};

void zap(stud &t, FILE *f)
{
	fscanf(f, "%s", t.fam);
	fscanf(f, "%s", t.gryp);
	for(int j = 0; j < 5; j++)
	{
		fscanf(f, "%d", &t.mark[j]);
	}
}

double summ(stud &t)
{
	int sum = 0;
	for(int j = 0; j < 5; j++)
		{
			sum = sum + t.mark[j];
		}
	return sum;
}

void vivod(stud t)
{
	printf("�������: %s\n", t.fam);
	printf("������: %s\n", t.gryp);
	printf("������: ");
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", t.mark[i]);
	}
	puts("");
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	int k, sumt = 0;
	char g[20], s[20];
	FILE *f;
	if ((f = fopen("file.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	fscanf(f, "%d", &k);
	stud *mas = new stud [k];
	for (int i = 0; i < k; i++)
	{
		zap(mas[i], f);
	}
	for (int i = 0; i < k; i++)
	{
		printf("\n������� %d:\n", i+1);
		vivod(mas[i]);
	}
	for (int i = 0; i < k; i++)
	{
		printf("�������: %s, ������� ����: %7.3lf\n", mas[i].fam, summ(mas[i]) / 5.0);
	}
	for (int i = 0; i < k; i++)
	{
		sumt = sumt + summ(mas[i]);
	}
	printf("������� ���� ���� ���������: %7.3lf\n", sumt / (5.0 * k));
	puts("������� ������:");
	gets_s(g);
	for (int i = 0; i < k; i++)
	{
		if (strcmp(mas[i].gryp, g) == 0)
		{
			vivod(mas[i]);
		}
	}
	fcloseall();
	_getch();
	return 0;
}

