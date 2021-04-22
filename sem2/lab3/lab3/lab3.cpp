// lab3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#pragma warning(disable:4996)

struct dssp {
	char fam[20];
	int mark;
	dssp *next;
	dssp *prev;
};

struct sp {
	char fam[20];
	int mark;
	sp *next;
};
/*
sp *f_st;

void vvod_stek()
{
	char s[20], s1[20];
	int k;
	sp *q, *p;
	puts("������� �������:");
	gets_s(s);
	puts("������� ������:");
	gets_s(s1);
	f_st = new sp;
	strcpy(f_st->fam, s);
	f_st->mark = atoi(s1);
	f_st->next = NULL;
	q = f_st;
	puts("���������� ���� 1/0?");
	scanf("%d", &k);
	getchar();
	while (k == 1)
	{
		p = q;
		q = new sp;
		puts("������� �������:");
		gets_s(s);
		puts("������� ������:");
		gets_s(s1);
		strcpy(q->fam, s);
		q->mark = atoi(s1);
		q->next = NULL;
		p->next = q;
		puts("���������� ���� 1/0?");
		scanf("%d", &k);
		getchar();
	}
}

void vivod_stek()
{
	sp *q = new sp;
	q = f_st;
	while (q != NULL)
	{
		printf("�������: %s, ������: %d\n", q->fam, q->mark);
		q = q->next;
	}
}

void sr_ar_st()
{
	sp *q;
	int kol = 0;
	double sum = 0;
	q = f_st;
	while (q != NULL)
	{
		kol++;
		sum += q->mark;
		q = q->next;
	}
	if (kol != 0)
	{
		printf("������� �������������� ������ �����:%7.3lf", sum / kol);
	}
	else puts("������. ���������� �������� ����� 0");
}

void dell()
{
	sp *q, *t, *t1;
	q = f_st;
	t = q;
	while (q != NULL)
	{
		t = q;
		q = q->next;
	}
	q = f_st;
	t1 = q;
	while (q->next != NULL)
	{
		t1 = q;
		q = q->next;
	}
	t1->next = NULL;
	delete t;
}

void delf()
{
	sp *t;
	t = f_st->next;
	delete f_st;
	f_st = t;
}

*/

dssp *first, *last;

void vvod_dv()
{
	char s[20], s1[20];
	dssp *q, *p;
	int k;
	puts("������� �������:");
	gets_s(s);
	puts("������� ������:");
	gets_s(s1);
	first = new dssp;
	strcpy(first->fam, s);
	first->mark = atoi(s1);
	first->prev = NULL;
	first->next = NULL;
	last = first;
	q = first;
	p = first;
	p->prev = NULL;
	puts("���������� ���� 1/0?");
	scanf("%d", &k);
	getchar();
	while (k == 1)
	{
		p = q;
		q = new dssp;
		puts("������� �������:");
		gets_s(s);
		puts("������� ������:");
		gets_s(s1);
		strcpy(q->fam, s);
		q->mark = atoi(s1);
		/*first->next = q;
		q->prev = first;
		q->next = NULL;
		last = q;*/
		q->prev = p;
		q->next = NULL;
		p->next = q;
		last = q;
		puts("���������� ���� 1/0?");
		scanf("%d", &k);
		getchar();
	}
}

void vivod_dv()
{
	dssp *q = new dssp;
	q = last;
	puts("��������������� ������: ");
	while (q != NULL)
	{
		printf("�������: %s, ������: %d\n", q->fam, q->mark);
		q = q->prev;
	}
}

void sr_ar_dv()
{
	dssp *q = new dssp;
	int kol = 0;
	double sum = 0;
	q = first;
	while (q != NULL)
	{
		kol++;
		sum += q->mark;
		q = q->next;
	}
	if (kol != 0)
	{
		printf("������� �������������� ������ �����:%7.3lf", sum / kol);
	}
	else puts("������. ���������� �������� ����� 0");
}

void delf_dv()
{
	dssp *t = first;
	first = first->next;
	first->prev = NULL;
	delete t;
}

void dell_dv()
{
	dssp *t = last;
	last = last->prev;
	last->next = NULL;
	delete t;
}

int main()
{
	setlocale(LC_CTYPE, "");
	/*puts("������ �� ������: ");
	vvod_stek();
	vivod_stek();
	sr_ar_st();
	delf();
	dell();
	puts("\n������� ������ � ��������� �������� �����:");
	vivod_stek();*/

	puts("������ � ��������������� �������: ");
	vvod_dv();
	vivod_dv();
	sr_ar_dv();
	delf_dv();
	dell_dv();
	puts("\n������� ������ � ��������� �������� ������:");
	vivod_dv();
	getch();
    return 0;
}

