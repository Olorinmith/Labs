// lab6.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	int a[10][10], b[10], m, n, mini=0, minj=0, maxi=0, maxj=0, max, min, temp, z, st1, st2, fl=1;
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
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n");
	//����� �������
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	//������� 1, �������� ������� ������ ���� � ��������� ��� ����
	max = a[0][0];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (a[i][j]>max)
			{
				max=a[i][j];
				maxi=i;
				maxj=j;
			}
		}
	}
	min = a[0][0];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (a[i][j]<=min)
			{
				min=a[i][j];
				mini=i;
				minj=j;
			}
		}
	}
	temp=a[maxi][maxj];
	a[maxi][maxj]=a[mini][minj];
	a[mini][minj]=temp;
	puts("\n������ ������� ������ ���� � ���� ���");
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	temp=a[mini][minj];
	a[mini][minj]=a[maxi][maxj];
	a[maxi][maxj]=temp;

	//������� 2, � ������ ����� ������� ������ � ���� ��� ��-�� ������ 10 �������� �� 0
	puts("\n������� ����� ������");
	scanf("%d", &z);
	for (int j=0; j<m; j++)
		{
			if (a[z-1][j]>10)
			{
				a[z-1][j]=0;
			}
		}
	printf("\n");
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

	//������� 3, �������� ������� �������, ������ ���� � ����
	puts("\n������� ������ �������� ������� ���� ��������:");
	scanf("%d", &st1);
	scanf("%d", &st2);
	for (int i=0; i<n; i++)
	{
		temp=a[i][st1-1];
		a[i][st1-1]=a[i][st2-1];
		a[i][st2-1]=temp;
	}
	printf("\n");
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}

	//������� 4, ��� ������� � �� ����� � �������� �
	puts("������� ������ B:");
	for (int i=0; i<n; i++)
	{
			scanf("%d", &b[i]);
	}
	printf("\n");
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			a[i][j]=a[i][j]+b[i];
		}
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	//������� 5, ������������� �� ����������� ������, ����� � ����
	puts("\n������� ����� ������");
	scanf("%d", &z);
	fl=1;
	
		for (int i=0; i<n; i++)
		{

		while(fl==1)
	
		for (int j=0; j<m-i-1; j++)
		{
			if(a[z-1][j]>a[z-1][j+1])
				{
					fl=1;
					temp=a[z-1][j];
					a[z-1][j]=a[z-1][j+1];
					a[z-1][j+1]=temp;
				}
		}
		}
	}
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}


