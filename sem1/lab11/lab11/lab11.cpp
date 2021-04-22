// lab11.cpp: определяет точку входа для консольного приложения.
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
	char s[10], *s1, *s2, *temps;
	int n, m;
	setlocale(LC_CTYPE, "");
	puts("Введите строку 10 символов: ");
	gets(s);
	puts(s);
	puts("");
	for(int i=0; i<10; i++)
	{
		printf("%c,  %d\n", s[i], s[i]);
	}
	
	puts("Введите размер строки s1:");
	scanf("%d", &n);
	getchar();
	s1 = new char [n+1];
	puts("Введите строку: ");
	gets(s1);
	puts(s1);
	puts("\nПервая по алфавиту:");
	if(strcmp(s1, s) >= 0)
	{
		puts(s);
		puts("\nВторая по алфавиту:");
		puts(s1);
	}
	else
	{
		puts(s1);
		puts("\nВторая по алфавиту:");
		puts(s);
	}
	puts("");
	strcat(s1, s);
	puts("Строка суммы:");
	puts(s1);

	puts("Введите размер строки s2:");
	scanf("%d", &m);
	getchar();
	s2 = new char [m+1];
	puts("Введите строкy s2:");
	gets(s2);
	temps = new char [m+1];
	for (int i = 0; i<m; i++)
	{
		if (s[i] == ' ')
		{
			puts(temps);
			temps = NULL;
		}
		else
		{
			temps = temps + s[i];
		}
	}
	puts(s2);
	getch();
	return 0;
}

