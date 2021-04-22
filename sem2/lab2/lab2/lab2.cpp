// lab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "stdio.h"
#include "locale.h"
#include "conio.h"
#pragma warning(disable:4996)

struct sp{
	int val;
	sp *add;
};

sp *first, *last;

void addfirst()
{
	int n;
	puts("\nВведите число, которое вставить в начало:");
	scanf("%d", &n);
	sp *q = new sp;
	q->val = n;
	q->add = first;
	first = q;
}

void addlast()
{
	int n;
	puts("\nВведите число, которое вставить в конец:");
	scanf("%d", &n);
	sp *q = new sp;
	q = first;
	sp *t = q;
	while (q != NULL)
	{
		t=q;
		q = q->add;
	}
	q = new sp;
	t->add = q;
	q->add = NULL;
	q->val = n;
}

void dellast()
{
	sp *q, *t, *t1;
	q = first;
	t = q;
	while (q != NULL)
	{
		t=q;
		q = q->add;
	}
	q = first;
	t1 = q;
	while (q->add != NULL)
	{
		t1 = q;
		q = q->add;
	}
	t1->add = NULL;
	delete t;
}

void kolvo(int k)
{
	int n = 0;
	sp *q;
	q = first;
	while (q != NULL)
	{
		if(q->val > k)
			n++;
		q = q->add;
	}
	printf("\nКоличество элементов больших введенного: %d\n", n);
}

void arif()
{
	int k = 0;
	double sum = 0;
	sp *q;
	q = first;
	while (q != NULL)
	{
		k++;
		sum+=q->val;
		q = q->add;
	}
	printf("\nСреднее арифметическое равно: %lf", sum/k);
}

void vivod()
{
	sp *q;
	q = first;
	puts("Список:");
	while (q != NULL)
	{
		printf("%d ", q->val);
		q = q->add;
	}
}

void vvod()
{
	char s[20];
	int k;
	sp *q, *p;
	puts("Введите число:");
	gets_s(s);
	first = new sp;
	first->val = atoi(s);
	first->add = NULL;
	q = first;
	puts("Продолжить ввод? 1/0");
	scanf("%d", &k);
	getchar();
	while (k == 1)
	{
		puts("Введите число:");
		gets_s(s);
		p = q;
		q = new sp;
		q->val = atoi(s);
		q->add = NULL;
		p->add = q;
		puts("Продолжить ввод? 1/0");
		scanf("%d", &k);
		getchar();
	}
}

void addnum()
{
	int k, n, s=1;
	puts("\nВведите номер элемента: ");
	scanf("%d", &k);
	puts("\nВведите значение: ");
	scanf("%d", &n);
	sp *q = first;
	sp *t = q, *t1 = q;
	for(int i = 0; i < k; i++)
	{
		if(i==k-2)
			t1 = q;
		t = q;
		q = q->add;
	}
	q = new sp;
	t1->add = q;
	q->add = t;
	q->val = n;
}

void max()
{
	int max = first->val;
	sp *q;
	q = first;
	while (q != NULL)
	{
		if (max < q->val)
			max = q->val;
		q = q->add;
	}
	printf("\nМаксимум равен: %d", max);
}

void odd()
{
	sp *q;
	q = first;
	printf("\nНечетные:");
	while (q != NULL)
	{
		if (q->val % 2 != 0)
			printf(" %d", q->val);
		q = q->add;
	}
}

void delf()
{
	sp *t;
	t = first->add;
	delete first;
	first = t;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	int k;
	vvod();
	vivod();
	arif();
	puts("\nВведите число, чтобы найти количество элементов больше него:");
	scanf("%d", &k);
	kolvo(k);
	addlast();
	vivod();
	addfirst();
	vivod();
	dellast();
	puts("\nУдалили последний элемент:");
	vivod();
	addnum();
	vivod();
	max();
	odd();
	delf();
	puts("\nУдалили первый элемент:");
	vivod();
	_getch();
	return 0;
}

