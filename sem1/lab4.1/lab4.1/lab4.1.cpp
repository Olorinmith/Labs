// lab4.1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <clocale>
#pragma warning(disable:4996)
#include "math.h"
#include "conio.h"
#include "locale.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	double a[10], min, max, z, k;
	int n, kmin, kmax, kolvo=0, i1, i2, kolvo1=0;
	puts("������� ������ �������");
	scanf("%d", &n);
	while (n>10) 
		{
			puts("����� ������� ������ ���� �� ����� 10");
			scanf("%d", &n);
		}	
	puts("������� ������");
	for (int i=0; i<n; i++)
		{
			scanf("%lf", &a[i]);
		}
	printf("\n");
	for (int i=0; i<n; i++)
		{
			printf("%7.3lf", a[i]);
		}
	min=a[0];
	kmin=0;
	for (int i=1; i<n; i++)
	{
		if (min>=a[i]) 
		{
			min=a[i];
			kmin=i;
		}
	}
	printf("\n������� �����:%7.3lf", min);
	max=a[0];
	kmax=0;
	for (int i=1; i<n; i++)
	{
		if (max<a[i]) 
		{
			max=a[i];
			kmax=i;
		}
	}
	kmax=kmax+1;
	printf("\n�������� �����:%7.3lf, ����� ������� ������������� �����: %d", max, kmax);
	puts("\n������� �������:");
	scanf("%lf", &z);
	for (int i=0; i<n; i++)
	{
		if (a[i]>z) 
		{
			kolvo++;
		}
	}
	printf("\n���������� ��������� ������ ����������: %d", kolvo);
	
	puts("\n������� ������� ��������� ������� ���� ��������:");
	scanf("%d", &i1);
	scanf("%d", &i2);
	k = a[i1-1];
	a[i1-1] = a[i2-1];
	a[i2-1] = k;
	for (int i=0; i<n; i++)
		{
			printf("%7.3lf", a[i]);
		}
	k = a[i2 - 1];
	a[i2 - 1] = a[i1 - 1];
	a[i1 - 1] = k;
	
	puts("\n�������� ������� ������ ���� � ��������� ��� ��������:");
	kmax=kmax-1;
	k=a[kmin];
	a[kmin]=a[kmax];
	a[kmax]=k;
	for (int i=0; i<n; i++)
		{
			printf("%7.3lf", a[i]);
		}
	k = a[kmax];
	a[kmax] = a[kmin];
	a[kmin] = k;

	int flag=0;
	for (int i=0; i<n; i++)
	{
			if (a[i] == 0)
			{
				flag = i;
			}
	}
	for (int i = flag; i < n; i++)
	{
		if (a[i] > 0)
		{
			kolvo1++;
		}
	}
	if (flag == 0) printf("\n���������� ������������� ��������� ����� ���������� 0: 0");
	else 
	printf("\n���������� ������������� ��������� ����� ���������� 0: %d", kolvo1);
	getch();
	return 0;
}