// lab11.cpp: определяет точку входа для консольного приложения.
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
	double x, y, z;
public:
	figura()
	{
		scanf("%lf", &x);
		scanf("%lf", &y);
		scanf("%lf", &z);
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
	virtual double plosh() = 0;
	virtual double vol()
	{
		return 0;
	}
	
};

class krug: public figura{
public:
	double r;
	krug()
	{
		scanf("%lf", &r);
	}
	double plosh()
	{
		return 3.14*r*r;
	}
};

class rect: public figura{
public:
	double a, b;
	rect()
	{
		scanf("%lf", &a);
		scanf("%lf", &b);
	}
	double plosh()
	{
		return a*b;
	}
};

class cylindr: public krug
{
public:
	double h;
	cylindr()
	{
		scanf("%lf", &h);
	}
	double vol()
	{
		return plosh() * h;
	}

};

class prism: public rect
{
public:
	double h;
	prism()
	{
		scanf("%lf", &h);
	}
	double vol()
	{
		return plosh() * h;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	figura *f;
	/*f = new figura();
	printf("x: %7.3lf, y: %7.3lf, z: %7.3lf\n", f->get_x(), f->get_y(), f->get_z());*/
	puts("Заполните поля круг(x, y, z, r):");
	krug k;
	puts("Заполните поля прямоугольник(x, y, z, a, b):");
	rect l;
	printf("krug: x: %7.3lf, y: %7.3lf, z: %7.3lf, r: %7.3lf, s: %7.3lf\n", k.get_x(), k.get_y(), k.get_z(), k.r, k.plosh());
	printf("Rect: x: %7.3lf, y: %7.3lf, z: %7.3lf, a: %7.3lf, b: %7.3lf, s: %7.3lf\n", l.get_x(), l.get_y(), l.get_z(), l.a, l.b, l.plosh());
	f = &k;
	printf("Krug: x: %7.3lf, y: %7.3lf, z: %7.3lf", f->get_x(), f->get_y(), f->get_z());
	//printf("r: %7.3lf", f->r);
	printf("s: %7.3lf\n", f->plosh());
	f = &l;
	printf("Rect: x: %7.3lf, y: %7.3lf, z: %7.3lf, s: %7.3lf\n", f->get_x(), f->get_y(), f->get_z(), f->plosh());
	puts("Заполните поля цилиндр(x, y, z, r, h)");
	cylindr c;
	printf("Cylindr: x:%7.3lf, y:%7.3lf, z:%7.3lf, v:%7.3lf\n", c.get_x(), c.get_y(), c.get_z(), c.vol());
	puts("Заполните поля призма(x, y, z, a, b, h)");
	prism p;
	printf("Prism: x:%7.3lf, y:%7.3lf, z:%7.3lf, v:%7.3lf\n", p.get_x(), p.get_y(), p.get_z(), p.vol());
	f = &c;
	printf("Cylindr: x:%7.3lf, y:%7.3lf, z:%7.3lf, v:%7.3lf\n", f->get_x(), f->get_y(), f->get_z(), f->vol());
	f = &p;
	printf("Prism: x:%7.3lf, y:%7.3lf, z:%7.3lf, v:%7.3lf\n", f->get_x(), f->get_y(), f->get_z(), f->vol());
	getch();
	return 0;
}

