// lab1.1.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	puts("������� �������:");
	gets_s(t.fam);
	puts("������� ������:");
	gets_s(t.gryp);
	puts("������� 5 ������:");
	for(int i = 0; i < 5; i++)
	{
		scanf_s("%d", &t.mark[i]);
	}
}

void vivod(stud t)
{
	printf("�������: %s", &t.fam);
	printf("������: %s\n", &t.gryp);
	printf("������: ");
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", &t.mark[i]);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	int k;
	puts("������� ���������� ���������:");
	scanf_s("%d", &k);
	stud *mas = new stud [k];
	for (int i = 0; i < k; i++)
	{
		zap(mas[i]);
	}
	for (int i = 0; i < k; i++)
	{
		printf("������� %d:\n", i);
		vivod(mas[i]);
	}
	_getch();
	return 0;
}

