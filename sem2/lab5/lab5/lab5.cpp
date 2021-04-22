// lab5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#pragma warning(disable:4996)

class magazin{
private:
		int val;
		int kol;
public:
		char name[20];
		int sumval()
		{
			return val*kol;
		}
		void set_val(int v)
		{
			val = v;
		}
		int get_val()
		{
			return val;
		}
		void set_kol(int k)
		{
			kol = k;
		}
		int get_kol()
		{
			return kol;
		}
};

void zap(magazin *t, FILE *f)
{
	int v, k;
	fscanf(f, "%s", t->name);
	fscanf(f, "%d", &v);
	fscanf(f, "%d", &k);
	t->set_val(v);
	t->set_kol(k);
}

void vivod(magazin t)
{
	printf("��������: %s, ���� 1 �������: %3d, ���������� ������: %3d", t.name, t.get_val(), t.get_kol());
	puts("");
}

void vivkol(magazin t[], int n, int k)
{
	int fl = 0;
	printf("������, ���������� ������� ������ ����������:");
	for (int i = 0; i < k; i++)
	{
		if(t[i].get_kol() > n)
		{
			printf(" %s", t[i].name);
			fl++;
		}
	}
	if(fl == 0) printf(" ����� ������� ���.");
	puts("");
}

void tovari(magazin t[], int k)
{
	puts("��������� ����� ������: ");
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		printf("��������: %s, ���� ����� ������: %4d\n", t[i].name, t[i].sumval());
		sum+=t[i].sumval();
	}
	printf("���� ���� ������� � ��������:       %d", sum);
}

void tovminkol(magazin t[], int k)
{
	printf("\n�������� ������ � ����������� �����������: ");
	int min = t[0].get_kol();
	for (int i = 0; i<k; i++)
	{
		if(t[i].get_kol() < min)
		{
			min = t[i].get_kol();
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(t[i].get_kol() == min)
		{
			printf("%s ", t[i].name);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	FILE *f;
	int k, n;
	if ((f = fopen("f.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	fscanf(f, "%d", &k);
	magazin *mas = new magazin[k];
	for (int i = 0; i < k; i++)
	{
		zap(&mas[i], f);
	}
	puts("������ �������: ");
	for (int i = 0; i < k; i++)
	{
		vivod(mas[i]);
	}
	puts("������� ���������� ������: ");
	scanf("%d", &n);
	vivkol(mas, n, k);
	tovari(mas, k);
	tovminkol(mas, k);
	getch();
	return 0;
}

