// lab11.1.cpp: ���������� ����� ����� ��� ����������� ����������.
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

int _tmain(int argc, _TCHAR* argv[])
{
	char s[10], *s1, *s2, *temps, *temps2;
	int n, m;
	setlocale(LC_CTYPE, "");
	puts("������� ������ 10 ��������: ");
	gets_s(s);
	puts(s);
	puts("");
	for(int i=0; i<10; i++)
	{
		printf("%c,  %d\n", s[i], s[i]);
	}
	
	puts("������� ������ ������ s1:");
	scanf("%d", &n);
	getchar();
	s1 = new char [n+1];
	puts("������� ������: ");
	gets(s1);
	puts(s1);
	puts("\n������ �� ��������:");
	if(strcmp(s1, s) >= 0)
	{
		puts(s);
		puts("\n������ �� ��������:");
		puts(s1);
	}
	else
	{
		puts(s1);
		puts("\n������ �� ��������:");
		puts(s);
	}
	puts("");
	strcat(s1, s);
	puts("������ �����:");
	puts(s1);

	puts("������� ������ ������ s2:");
	scanf("%d", &m);
	getchar();
	s2 = new char [m+1];
	temps2 = new char[m + 1];
	puts("������� �����y s2:");
	gets(s2);
	strcpy(temps2, s2);
	temps = strtok(temps2, " ");
	while (temps != NULL)
	{
		printf("\n%s", temps);
		temps = strtok(NULL, " ");
	}
	getch();
	return 0;
}