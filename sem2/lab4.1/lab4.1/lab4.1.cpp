// lab4.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#pragma warning(disable:4996)

class student{
private:
	char fam[20];
	int year;
	int mark[3];
public:
	double sr()
	{
		int sum = 0;
		sum = mark[0]+mark[1]+mark[2];
		return (sum/3.0);
	}
	void set_year(int y)
	{
		year = y;
	}
	int get_year()
	{
		return year;
	}
	void set_fam(char s[20])
	{
		strcpy(fam, s);
	}
	char* get_fam()
	{
		return fam;
	}
	void set_mark(int a[3])
	{
		for(int i = 0; i<3; i++)
		{
			mark[i] = a[i];
		}
	}
	int* get_mark()
	{
		return mark;
	}
	int get_mark_num(int n)
	{
		return mark[n-1];
	}
};

void zap(student *t, FILE *f)
{
	char s[20];
	int m[3], y;
	fscanf(f, "%s", s);
	fscanf(f, "%d", &y);
	for(int i =0; i<3; i++)
	{
		fscanf(f, "%d", &m[i]);
	}
	t->set_fam(s);
	t->set_year(y);
	t->set_mark(m);
}

void vivod(student t)
{
	printf("Фамилия: %s, Год поступления: %d, Оценки: ", t.get_fam(), t.get_year());
	for(int i = 0; i < 3; i++)
	{
		printf(" %d", t.get_mark_num(i+1));
	}
	puts("");
}

int sm(student t)
{
	int sum = 0;
	sum = t.get_mark_num(1)+t.get_mark_num(2)+t.get_mark_num(3);
	return sum;
}

bool chek(student t)
{
	if((t.get_mark_num(1) >= 4) && (t.get_mark_num(2) >= 4) && (t.get_mark_num(3) >= 4))
		return 1;
	else return 0;
}

void sort(student mas[], int k)
{
	int fl;
	do
	{
		fl = 1;
		for(int i = 0; i<k; i++)
		{
			if(strcmp(mas[i].get_fam(), mas[i+1].get_fam()) > 0)
			{
				student temp;
				temp = mas[i];
				mas[i] = mas[i+1];
				mas[i+1] = temp;
				fl = 0;
			}
		}
	}
	while (fl == 0);
}

void vvod_f(student mas[], FILE *f2, int k)
{
	for(int i = 0; i<k; i++)
	{
		fprintf(f2, "%s\n", mas[i].get_fam());
		fprintf(f2, "%d\n", mas[i].get_year());
		for(int j = 0; j<3; j++)
		{
			fprintf(f2, "%d ", mas[i].get_mark_num(j+1));
		}
		fprintf(f2, "\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	//student a;
	/*puts("Введите фамилию: ");
	gets(s);
	puts("Введите год поступления: ");
	scanf("%d", &y);
	puts("Введите три оценки: ");
	for(int i =0; i<3; i++)
	{
		scanf("%d", &m[i]);
	}
	a.set_fam(s);
	a.set_year(y);
	a.set_mark(m);
	printf("Студент: %s, Год поступления: %d, Средняя оценка: %7.3lf", a.get_fam(), a.get_year(), a.sr());*/
	FILE *f, *f2;
	int k;
	double sum = 0;
	if ((f = fopen("f.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	if ((f2 = fopen("f2.txt", "w")) == NULL)
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
			printf("%s ", (mas[i]).get_fam());
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
			printf("%s ", (mas[i]).get_fam());
		}
	}
	int j;
	puts("\nВведите номер оценки:");
	scanf("%d", &j);
	printf("\n%d оценки студентов: ", j);
	for (int i = 0; i<k; i++)
	{
		printf("%d ", (mas[i]).get_mark_num(j));
	}
	sort(mas, k);
	vvod_f(mas, f2, k);
	puts("\nЗапись в файл завершена.");
	fcloseall();
	getch();
	return 0;
}

