// lab9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "math.h"
#pragma warning(disable:4996)

class figura{
private:
	double x;
protected:
	double y;
public:
	double z;
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
	double distance()
	{
		return sqrt(x*x+y*y+z*z);
	}
	figura()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	figura(FILE *f)
	{
		fscanf(f, "%lf", &x);
		fscanf(f, "%lf", &y);
		fscanf(f, "%lf", &z);
	}
};

class okr:public figura{
private:
	double r;
public:
	double get_r()
	{
		return r;
	}
	okr()
	{
		r = 0;
	}
	okr(FILE *f):figura(f)
	{
		fscanf(f, "%lf", &r);
	}
	double plosh()
	{
		return 3.14*r*r;
	}

};

class col_okr:public okr{
private:
	char color[20];
public:
	double perim()
	{
		return 2*3.14*get_r();
	}
	char* get_color()
	{
		return color;
	}
	col_okr()
	{
		strcpy(color, "\0");
	}
	col_okr(FILE *f):okr(f)
	{
		fscanf(f, "%s", &color);
	}
};

class kvadrat:public figura{
private:
	double a;
public:
	double plosh()
	{
		return a*a;
	}
	kvadrat()
	{
		a = 0;
	}
	kvadrat(FILE *f):figura(f)
	{
		fscanf(f, "%lf", &a);
	}
};

double min_pl_kv(kvadrat *mas, int k)
{
	double min = mas[0].plosh();
	for(int i = 0; i < k; i++)
	{
		if(min > mas[i].plosh())
		{
			min = mas[i].plosh();
		}
	}
	for(int i = 0; i < k; i++)
	{
		if(mas[i].plosh() == min)
		{
			printf("Квадрат: %7.3lf %7.3lf %7.3lf, Расстояние до центра: %7.3lf, Площадь: %7.3lf\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].distance(), mas[i].plosh());
		}
	}
	return min;
}

void men_pl_okr(col_okr *mas, int k, double m)
{
	int fl = 0;
	for(int i = 0; i < k; i++)
	{
		if(mas[i].plosh() < m)
		{
			printf("Окружность: %7.3lf %7.3lf %7.3lf, Расстояние до центра: %7.3lf\n Цвет: %10s, Площадь: %7.3lf, Периметр: %7.3lf\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].distance(), mas[i].get_color(), mas[i].plosh(), mas[i].perim());
			fl = 1;
		}
	}
	if (fl == 0) puts("Таких окружностей нет!");
}

void colcmp(col_okr *mas, int k)
{
	int fl = 0;
	int fl1 = 0;
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(strcmp(mas[i].get_color(), mas[j].get_color()) == 0)
				fl1 = 1;
		}
		if (fl1 == 0)
		{
			for(int j = i+1; j < k; j++)
			{
				if((strcmp(mas[i].get_color(), mas[j].get_color()) == 0) && (fl == 1))
				{
					printf("Окружность: %7.3lf %7.3lf %7.3lf, Расстояние до центра: %7.3lf\n Цвет: %10s, Площадь: %7.3lf, Периметр: %7.3lf\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].distance(), mas[i].get_color(), mas[i].plosh(), mas[i].perim());
				}
				if((strcmp(mas[i].get_color(), mas[j].get_color()) == 0) && (fl == 0))
				{
					printf("Окружности цвета %s:\n", mas[i].get_color());
					printf("Окружность: %7.3lf %7.3lf %7.3lf, Расстояние до центра: %7.3lf\n Цвет: %10s, Площадь: %7.3lf, Периметр: %7.3lf\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].distance(), mas[i].get_color(), mas[i].plosh(), mas[i].perim());
					printf("Окружность: %7.3lf %7.3lf %7.3lf, Расстояние до центра: %7.3lf\n Цвет: %10s, Площадь: %7.3lf, Периметр: %7.3lf\n", mas[j].get_x(), mas[j].get_y(), mas[j].z, mas[j].distance(), mas[j].get_color(), mas[j].plosh(), mas[j].perim());
					fl = 1;
				}
			}
		}
		fl1 = 0;
		fl = 0;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	FILE *fk, *fo;
	char s[20];
	int kk = 0, ko = 0;
	double min_kv_pl;
	if ((fk = fopen("fk.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	if ((fo = fopen("fo.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	while(fgets(s, 80, fk) != NULL)
	{
		kk++;
	}
	while(fgets(s, 80, fo) != NULL)
	{
		ko++;
	}
	rewind(fk);
	rewind(fo);
	col_okr *masok = new col_okr[ko];
	for(int i = 0; i < ko; i++)
	{
		masok[i] = col_okr(fo);
	}
	kvadrat *maskv = new kvadrat[kk];
	for(int i = 0; i < kk; i++)
	{
		maskv[i] = kvadrat(fk);
	}
	puts("Квадрат с минимальной площадью:");
	min_kv_pl = min_pl_kv(maskv, kk);
	puts("Окружности с площадью меньше чем наименьшая площадь квадрата:");
	men_pl_okr(masok, ko, min_kv_pl);
	colcmp(masok, ko);
	fcloseall();
	getch();
	return 0;
}

