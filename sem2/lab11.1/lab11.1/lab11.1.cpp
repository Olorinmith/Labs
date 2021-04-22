// lab11.1.cpp: определяет точку входа для консольного приложения.
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
		r = 0;
	}
	krug(FILE *f) : figura(f)
	{
		fscanf(f, "%lf", &r);
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
		a = 0;
		b = 0;
	}
	rect(FILE *f) : figura(f)
	{
		fscanf(f, "%lf", &a);
		fscanf(f, "%lf", &b);
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
		h = 0;
	}
	cylindr(FILE *f) : krug(f)
	{
		fscanf(f, "%lf", &h);
	}
	double vol()
	{
		return plosh() * h;
	}
	double plosh()
	{
		return 2*3.14*r*h + 2*3.14*r*r;
	}
};

class prism: public rect
{
public:
	double h;
	prism()
	{
		h = 0;
	}
	prism(FILE *f) : rect(f)
	{
		fscanf(f, "%lf", &h);
	}
	double vol()
	{
		return plosh() * h;
	}
	double plosh()
	{
		return 2*a*b + 2*a*h + 2*b*h;
	}
};

void vivod(krug *mas, int k)
{
	figura *af;
	for(int i = 0; i < k; i++)
	{
		af = &mas[i];
		printf("x:%7.3lf, y:%7.3lf, z:%7.3lf, r:%7.3lf, s:%7.3lf\n", af->get_x(), af->get_y(), af->get_z(), mas[i].r, af->plosh());
	}
}

void vivod(rect *mas, int k)
{
	figura *af;
	for(int i = 0; i < k; i++)
	{
		af = &mas[i];
		printf("x:%7.3lf, y:%7.3lf, z:%7.3lf, a:%7.3lf, b:%7.3lf, s:%7.3lf\n", af->get_x(), af->get_y(), af->get_z(), mas[i].a, mas[i].b, af->plosh());
	}
}

void vivod(cylindr *mas, int k)
{
	figura *af;
	for(int i = 0; i < k; i++)
	{
		af = &mas[i];
		printf("x:%7.3lf, y:%7.3lf, z:%7.3lf, r:%7.3lf, h:%7.3lf, v:%7.3lf, s:%7.3lf\n", af->get_x(), af->get_y(), af->get_z(), mas[i].r, mas[i].h, mas[i].vol(), af->plosh());
	}
}

void vivod(prism *mas, int k)
{
	figura *af;
	for(int i = 0; i < k; i++)
	{
		af = &mas[i];
		printf("x:%7.3lf, y:%7.3lf, z:%7.3lf, a:%7.3lf, b:%7.3lf, s:%7.3lf, v:%7.3lf\n", af->get_x(), af->get_y(), af->get_z(), mas[i].a, mas[i].b, af->plosh(), af->vol());
	}
}

void maxpl(cylindr *mas, int k)
{
	double max = mas[0].plosh();
	for(int i = 0; i < k; i++)
	{
		if(mas[i].plosh() > max)
		{
			max = mas[i].plosh();
		}
	}
	for(int i = 0; i < k; i++)
	{
		if(mas[i].plosh() == max)
		{
			printf("x:%7.3lf, y:%7.3lf, z:%7.3lf, r:%7.3lf, h:%7.3lf, v:%7.3lf, s:%7.3lf\n", mas[i].get_x(), mas[i].get_y(), mas[i].get_z(), mas[i].r, mas[i].h, mas[i].vol(), mas[i].plosh());
		}
	}
}

double sro(prism *mas, int k)
{
	double sum = 0;
	for(int i = 0; i < k; i++)
	{
		sum += mas[i].vol();
	}
	return sum / k;
}



int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	FILE *fk, *fr, *fc, *fp, *fv;
	char s[50];
	int kk = 0, kr = 0, kc = 0, kp = 0;
	if ((fk = fopen("fk.txt", "r")) == NULL)
	{
		puts("ERROR");
		getch();
		return 0;
	}
	if ((fv = fopen("fv.txt", "w")) == NULL)
	{
		puts("ERROR");
		getch();
		return 0;
	}
	if ((fr = fopen("fr.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	if ((fc = fopen("fc.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	if ((fp = fopen("fp.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	while(fgets(s, 200, fk) != NULL)
	{
		kk++;
	}
	while(fgets(s, 200, fr) != NULL)
	{
		kr++;
	}
	while(fgets(s, 200, fc) != NULL)
	{
		kc++;
	}
	while(fgets(s, 200, fp) != NULL)
	{
		kp++;
	}
	rewind(fk);
	rewind(fr);
	rewind(fc);
	rewind(fp);
	krug *kmas = new krug[kk];
	for(int i = 0; i < kk; i++)
	{
		kmas[i] = krug(fk);
	}
	rect *rmas = new rect[kr];
	for(int i = 0; i < kr; i++)
	{
		rmas[i] = rect(fr);
	}
	cylindr *cmas = new cylindr[kc];
	for(int i = 0; i < kc; i++)
	{
		cmas[i] = cylindr(fc);
	}
	prism *pmas = new prism[kp];
	for(int i = 0; i < kp; i++)
	{
		pmas[i] = prism(fp);
	}
	puts("Krug:");
	vivod(kmas, kk);
	puts("Rect:");
	vivod(rmas, kr);
	puts("cylindr:");
	vivod(cmas, kc);
	puts("prism:");
	vivod(pmas, kp);
	puts("Цилиндры с максимальной площадью поверхности:");
	maxpl(cmas, kc); 
	double sr = sro(pmas, kp);
	for(int i = 0; i < kp; i++)
	{
		if(pmas[i].vol() >= sr)
			fprintf(fv, "x:%7.3lf, y:%7.3lf, z:%7.3lf, a:%7.3lf, b:%7.3lf, s:%7.3lf, v:%7.3lf\n", pmas[i].get_x(), pmas[i].get_y(), pmas[i].get_z(), pmas[i].a, pmas[i].b, pmas[i].plosh(), pmas[i].vol());
	}
	fcloseall();
	getch();
	return 0;
}

