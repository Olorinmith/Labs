// lab8.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "math.h"
#pragma warning(disable:4996)

class centr{
private:
	double x;
protected:
	double y;
public:
	double z;
	centr(){
	x = 0;
	y = 0;
	z = 0;
	}
	centr(FILE *f)
	{
		fscanf(f, "%lf", &x);
		fscanf(f, "%lf", &y);
		fscanf(f, "%lf", &z);
	}
	double get_x()
	{
		return x;
	}
	double distance()
	{
		return sqrt(x*x+y*y+z*z);
	}
};

class sphere:public centr{
private:
	double r;
public:
	double get_r()
	{
		return r;
	}
	double get_y()
	{
		return y;
	}
	sphere(){
	r = 0;
	}
	sphere(FILE *f):centr(f)
	{
		fscanf(f, "%lf", &r);
	}
};

class color:public sphere{
private:
	char s_color[20];
public:
	char* get_s()
	{
		return s_color;
	}
	color()
	{
		strcpy(s_color, "\0");
	}
	color(FILE *f):sphere(f)
	{
		fscanf(f, "%s", &s_color);
	}
};

void vivod(color *mas, int k)
{
	for(int i = 0; i<k; i++)
	{
		printf("—фера %d: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", i+1, mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].get_r(), mas[i].distance(), mas[i].get_s());
	}
}

void maxx(color *mas, int k)
{
	double max = mas[0].get_x();
	for(int i = 0; i < k; i++)
	{
		if(mas[i].get_x() > max)
		{
			max = mas[i].get_x();
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i].get_x() == max)
		{
			printf("—фера: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].get_r(), mas[i].distance(), mas[i].get_s());
		}
	}
}

void maxz(color *mas, int k)
{
	double max = mas[0].z;
	for(int i = 0; i < k; i++)
	{
		if(mas[i].z > max)
		{
			max = mas[i].z;
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i].z == max)
		{
			printf("—фера: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].get_r(), mas[i].distance(), mas[i].get_s());
		}
	}
}

void maxy(color *mas, int k)
{
	double max = mas[0].get_y();
	for(int i = 0; i < k; i++)
	{
		if(mas[i].get_y() > max)
		{
			max = mas[i].get_y();
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i].get_y() == max)
		{
			printf("—фера: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].get_r(), mas[i].distance(), mas[i].get_s());
		}
	}
}

void maxdis(color *mas, int k)
{
	double max = mas[0].distance();
	for(int i = 0; i < k; i++)
	{
		if(mas[i].distance() > max)
		{
			max = mas[i].distance();
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i].distance() == max)
		{
			printf("—фера: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].get_r(), mas[i].distance(), mas[i].get_s());
		}
	}
}

void colcmp(color *mas, int k)
{
	int fl = 0;
	int fl1 = 0;
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(strcmp(mas[i].get_s(), mas[j].get_s()) == 0)
				fl1 = 1;
		}
		if (fl1 == 0)
		{
			for(int j = i+1; j < k; j++)
			{
				if((strcmp(mas[i].get_s(), mas[j].get_s()) == 0) && (fl == 1))
				{
					printf("—фера: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", mas[j].get_x(), mas[j].get_y(), mas[j].z, mas[j].get_r(), mas[j].distance(), mas[j].get_s());
				}
				if((strcmp(mas[i].get_s(), mas[j].get_s()) == 0) && (fl == 0))
				{
					printf("—феры цвета %s:\n", mas[i].get_s());
					printf("—фера: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].get_r(), mas[i].distance(), mas[i].get_s());
					printf("—фера: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", mas[j].get_x(), mas[j].get_y(), mas[j].z, mas[j].get_r(), mas[j].distance(), mas[j].get_s());
					fl = 1;
				}
			}
		}
		fl1 = 0;
		fl = 0;
	}
}

void sort(color *mas, int k)
{
	int fl;
	color tmp;
	do
	{
		fl = 0;
		for(int i = 0; i < k-1; i++)
		{
			if(mas[i].get_r()>mas[i+1].get_r())
			{
				tmp = mas[i];
				mas[i] = mas[i+1];
				mas[i+1] = tmp;
				fl = 1;
			}
		}
	}
	while(fl == 1);
}

void zap(FILE *fe, color *mas, int k)
{
	for(int i = 0; i<k; i++)
	{
		fprintf(fe, "%7.3lf %7.3lf %7.3lf %7.3lf %s\n", mas[i].get_x(), mas[i].get_y(), mas[i].z, mas[i].get_r(), mas[i].get_s());
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	/*puts("заполните пол€ объекта centr(x, y, z):");
	centr a;
	puts("заполните пол€ объекта sphere(x, y, z, r):");
	sphere b;
	puts("заполните пол€ объекта color(x, y, z, r, s_color):");
	color c;
	puts("заполните пол€ объекта centr(x, y, z):");
	scanf("%lf", &a.x);
	scanf("%lf", &a.y);
	scanf("%lf", &a.z);
	puts("заполните пол€ объекта sphere(x, y, z, r):");
	scanf("%lf", &b.x);
	scanf("%lf", &b.y);
	scanf("%lf", &b.z);
	scanf("%lf", &b.r);
	puts("заполните пол€ объекта color(x, y, z, r, s_color):");
	scanf("%lf", &c.x);
	scanf("%lf", &c.y);
	scanf("%lf", &c.z);
	scanf("%lf", &c.r);
	scanf("%s", &c.s_color);
	printf("ќбъект а: x: %7.3lf, y: %7.3lf, z: %7.3lf, distance: %7.3lf\n", a.get_x(), a.get_y(), a.z, a.distance());
	printf("ќбъект b: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf, distance: %7.3lf\n", b.get_x(), b.get_y(), b.z, b.get_r(), b.distance());
	printf("ќбъект c: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf\n distance: %7.3lf, color: %s\n", c.get_x(), c.get_y(), c.z, c.get_r(), c.distance(), c.get_s());*/
	FILE *f, *fe;
	int k = 0;
	char s[20];
	if ((f = fopen("f.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	if ((fe = fopen("fe.txt", "w")) == NULL)
	{
		getch();
		return 0;
	}
	while(fgets(s, 80, f) != NULL)
	{
		k++;
	}
	rewind(f);
	color *mas = new color[k];
	for(int i = 0; i < k; i++)
	{
			mas[i] = color(f);
	}
	vivod(mas, k);
	puts("\n—фера с максимальной координатой х:");
	maxx(mas, k);
	puts("\n—фера с максимальной координатой y:");
	maxy(mas, k);
	puts("\n—фера с максимальной координатой z:");
	maxz(mas, k);
	puts("\n—феры максимально удаленные от центра:");
	maxdis(mas, k);
	puts("\n—феры с одинаковыми цветами:");
	colcmp(mas, k);
	sort(mas, k);
	zap(fe, mas, k);
	puts("‘айл fe.txt записан!");
	fcloseall();
	getch();
	return 0;
}

