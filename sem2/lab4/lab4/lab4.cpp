// lab4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#pragma warning(disable:4996)

class student{
public:
	char fam[20];
	int year;
	int mark[3];
	double sr();
};

double student::sr()
{
	int sum = 0;
	sum = mark[0]+mark[1]+mark[2];
	return (sum/3.0);
}

void zap(student *t, FILE *f)
{
	fscanf(f, "%s", t->fam);
	fscanf(f, "%d", &t->year);
	for(int i =0; i<3; i++)
	{
		fscanf(f, "%d", &t->mark[i]);
	}
}

void vivod(student t)
{
	printf("Фамилия: %s, Год поступления: %d, Оценки: ", t.fam, t.year);
	for(int i = 0; i < 3; i++)
	{

		printf(" %d", t.mark[i]);
	}
	puts("");
}

int sm(student t)
{
	int sum = 0;
	sum = t.mark[0]+t.mark[1]+t.mark[2];
	return sum;
}

bool chek(student t)
{
	if((t.mark[0] >= 4) && (t.mark[1] >= 4) && (t.mark[2] >= 4))
		return 1;
	else return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	/*student a;
	puts("Введите фамилию: ");
	gets(a.fam);
	puts("Введите год поступления: ");
	scanf("%d", &a.year);
	puts("Введите три оценки: ");
	for(int i =0; i<3; i++)
	{
		scanf("%d", &a.mark[i]);
	}
	getchar();
	printf("Студент: %s, Год поступления: %d, Средняя оценка: %7.3lf", a.fam, a.year, a.sr());	*/
	FILE *f;
	int k;
	double sum = 0;
	if ((f = fopen("f.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	fscanf(f, "%d", &k);
	student *mas = new student[k];
	for (int i = 0; i < k; i++)
	{
		zap(&mas[i], f);
	}
	puts("Студенты: ");
	for (int i = 0; i < k; i++)
	{
		vivod(mas[i]);
	}
	for (int i = 0; i<k; i++)
	{
		sum += sm(mas[i]);
	}
	printf("Среднее арифметическое оценок всех студентов: %7.3lf\n", sum/(k*3));
	printf("Фамилии студентов-хорошистов: ");
	int fl = 0;
	for (int i = 0; i<k; i++)
	{
		if(chek(mas[i]))
		{
			printf("%s ", (mas[i]).fam);
			fl++;
		}
	}
	if(fl == 0) printf("Таких студентов нет.");
	double min;
	min = mas[0].sr();
	printf("\nФамилии студентов с минимальной средней оценкой: ");
	for (int i = 0; i<k; i++)
	{
		if(mas[i].sr() < min)
		{
			min = mas[i].sr();
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i].sr() == min)
		{
			printf("%s ", (mas[i]).fam);
		}
	}
	getch();
	return 0;
}

