// lab5.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	double a[10][10], max, sum=0, temp, tsum=0, summax=0;
	int n, m, z, n1, m1, n2, m2, maxj;
	puts("������� ���������� ����� � ���������� �������� �� ����������� 10:");
	do 
	{
		scanf("%d", &n);
		scanf("%d", &m);
		if (n>10 || m>10) puts("\n������ �� ������ ��������� 10");
	}
	while (n>10 || m>10);
	//���� �������
	puts("������� ������:");
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			scanf("%lf", &a[i][j]);
		}
	}
	//����� �������
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%7.3lf", a[i][j]);
		}
		printf("\n");
	}
	//������� 1, ����� ������������ ������� �������
	max=a[0][0];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (a[i][j] > max) max = a[i][j];
		}
	}
	printf("������������ ������� ������� �����: %lf", max);
	//������� 2, ����� ������� �������������� ������ ���� � ����
	puts("\n������� ����� ������:");
	scanf("%d", &z);
	for (int j=0; j<m; j++)
	{
		sum = sum + a[z-1][j];
	}
	printf("\n������� �������������� ������ %d �����: %lf", z, sum/m);
	//������� 3, �������� ������� ��������, ������� ������� � ����������
	puts("\n������� ������� ������� ��������:");
	scanf("%d", &n1);
	scanf("%d", &m1);
	puts("\n������� ������� ������� ��������:");
	scanf("%d", &n2);
	scanf("%d", &m2);
	temp = a[n1-1][m1-1];
	a[n1-1][m1-1] = a[n2-1][m2-1];
	a[n2-1][m2-1] = temp;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%7.3lf", a[i][j]);
		}
		printf("\n");
	}
	//������� 4, ����� ����� ������� � ������� ���������� ����� ���������

	for (int j=0; j<m; j++)
	{
		summax = summax +a[1][j];
	}
	maxj = 0;
	for (int j=0; j<m; j++)
	{
		for (int i=0; i<n; i++)
		{
			tsum = tsum + a[i][j];
		}
		if (summax < tsum) maxj = j;
	}
	printf("\n����� ������� � ������� ����� ��������� ����������� �����: %d", maxj+1);
	getch();
	return 0;
}

