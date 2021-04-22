// lab6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "math.h"
#pragma warning(disable:4996)

class sphere{
private:
	double x, y, z, r;
public:
	void set_x(double x1)
	{
		x = x1;
	}
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
	double get_z()
	{
		return z;
	}
	double get_r()
	{
		return r;
	}
	sphere()
	{
		x = 0;
		y = 0;
		z = 0;
		r = 0;
	}
	sphere(double a)
	{
		x = a;
		y = 0;
		z = 0;
		r = 0;
	}
	sphere(double a, double b)
	{
		x = a;
		y = b;
		z = 0;
		r = 0;
	}
	sphere(double a, double b, double c)
	{
		x = a;
		y = b;
		z = c;
		r = 99;
	}
	sphere(FILE *f)
	{
		fscanf(f, "%lf", &x);
		fscanf(f, "%lf", &y);
		fscanf(f, "%lf", &z);
		fscanf(f, "%lf", &r);
	}
	double rast()
	{
		double ras = sqrt(x*x + y*y + z*z);
		return ras;
	}
	~sphere()
	{
		puts("Память очищена");
	};
};

//void zap(sphere *t, FILE *f, int k)
//{
//		fscanf(f, "%lf", &t->x);
//		fscanf(f, "%lf", &t->y);
//		fscanf(f, "%lf", &t->z);
//		fscanf(f, "%lf", &t->r);
//}

void vivod(sphere *t, int k)
{
	printf("Координаты:%7.3lf,%7.3lf,%7.3lf, Радиус: %7.3lf\n", t->get_x(), t->get_y(), t->get_z(), t->get_r());
}

void spminr(sphere **t, int k)
{
	printf("\nСферы с минимальным радиусом: \n");
	double min = t[0]->get_r();
	for(int i = 0; i < k; i++)
	{
		if(t[i]->get_r() < min)
		{
			min = t[i]->get_r();
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(t[i]->get_r() == min)
		{
			printf("Координаты:%7.3lf,%7.3lf,%7.3lf, Радиус: %7.3lf\n Расстояние до центра: %7.3lf\n", t[i]->get_x(), t[i]->get_y(), t[i]->get_z(), t[i]->get_r(), t[i]->rast());
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	FILE *f;
	int k;
	double xt, yt, zt, rt, r1;
	puts("Работа с конструкторами:");
	puts("Введите все данные о сфере: ");
	scanf("%lf", &xt);
	scanf("%lf", &yt);
	scanf("%lf", &zt);
	scanf("%lf", &rt);
	sphere sp1;
	sphere sp2(xt);
	sphere sp3(xt, yt);
	sphere sp4(xt, yt, zt);
	printf("Координаты: %7.3lf, %7.3lf, %7.3lf, Радиус: %7.3lf\n", sp1.get_x(), sp1.get_y(), sp1.get_z(), sp1.get_r());
	printf("Координаты: %7.3lf, %7.3lf, %7.3lf, Радиус: %7.3lf\n", sp2.get_x(), sp2.get_y(), sp2.get_z(), sp2.get_r());
	printf("Координаты: %7.3lf, %7.3lf, %7.3lf, Радиус: %7.3lf\n", sp3.get_x(), sp3.get_y(), sp3.get_z(), sp3.get_r());
	printf("Координаты: %7.3lf, %7.3lf, %7.3lf, Радиус: %7.3lf\n", sp4.get_x(), sp4.get_y(), sp4.get_z(), sp4.get_r());
	puts("Работа с массивом сфер: ");
	if ((f = fopen("f.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	fscanf(f, "%d", &k);
	sphere **mas = new sphere*[k+1];
	for(int i = 0; i< k+1; i++) mas[i] = new sphere(f);
	/*for(int i = 0; i<k; i++)
	{
		zap(mas[i], f, k);
	}*/
	for(int i = 0; i<k; i++)
	{
		vivod(mas[i], k);
	}
	puts("Введите радиус: ");
	scanf("%lf", &r1);
	puts("Координаты сфер с радиусом больше введенного:");
	int fl = 0;
	for(int i = 0; i<k; i++)
	{
		if(mas[i]->get_r() > r1)
		{
			printf("Координаты: %7.3lf, %7.3lf, %7.3lf\n", mas[i]->get_x(), mas[i]->get_y(), mas[i]->get_z());
			fl = 1;
		}
	}
	if(fl == 0) printf("Таких сфер нет!");
	puts("\nСферы с координатой х больше 0: ");
	for(int i = 0; i<k; i++)
	{
		if(mas[i]->get_x() > 0)
		{
			printf("Координаты:%7.3lf,%7.3lf,%7.3lf, Радиус: %7.3lf\n Расстояние до центра: %7.3lf\n", mas[i]->get_x(), mas[i]->get_y(), mas[i]->get_z(), mas[i]->get_r(), mas[i]->rast());
			mas[i]->set_x(-(mas[i]->get_x()));
		}
	}
	spminr(mas, k);
	getch();
	return 0;
}
