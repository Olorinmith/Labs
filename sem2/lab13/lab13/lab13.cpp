// lab13.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "math.h"
#pragma warning(disable:4996)

class base{
private:
	char fam[20];
public:
	char* get_fam()
	{
		return fam;
	}
	virtual double nalog() = 0;
	base()
	{
		strcpy(fam, "\0");
	}
	base(char *s)
	{
		strcpy(fam, s);
	}
};

class flat : public base{
private:
	double cost;
public:
	double nalog()
	{
		return (cost / 500);
	}
	double get_cost()
	{
		return cost;
	}
	flat()
	{
		cost = 0;
	}
	flat(char *sf, FILE *f) : base(sf)
	{
		fscanf(f, "%lf", &cost);
	}
};

class house : public base{
private:
	double space;
public:
	double nalog()
	{
		return (space * 10);
	}
	double get_space()
	{
		return space;
	}
	house()
	{
		space = 0;
	}
	house(char *sf, FILE *f) : base(sf)
	{
		fscanf(f, "%lf", &space);
	}
};

class car : public base{
private:
	double power;
public:
	double nalog()
	{
		return (power * 100);
	}
	double get_power()
	{
		return power;
	}
	car()
	{
		power  = 0;
	}
	car(char *sf, FILE *f) : base(sf)
	{
		fscanf(f, "%lf", &power);
	}
};

void vivod(flat *mf, house *mh, car *mc, int kf, int kh, int kc)
{
	puts("Квартиры:");
	for(int i = 0; i < kf; i++)
	{
		printf("Фамилия: %s, квартира: %.1lf , налог: %.1lf\n", mf[i].get_fam(), mf[i].get_cost(), mf[i].nalog());
	}
	puts("Дома:");
	for(int i = 0; i < kh; i++)
	{
		printf("Фамилия: %s, дом: %.1lf , налог: %.1lf\n", mh[i].get_fam(), mh[i].get_space(), mh[i].nalog());
	}
	puts("Машины:");
	for(int i = 0; i < kc; i++)
	{
		printf("Фамилия: %s, машина: %.1lf , налог: %.1lf\n", mc[i].get_fam(), mc[i].get_power(), mc[i].nalog());
	}
}

void find(flat *mf, house *mh, car *mc, int kf, int kh, int kc, char *s)
{
	double sum = 0;
	int fl = 0;
	printf("Фамилия: %s", s);
	for(int i = 0; i < kf; i++)
	{
		if(strcmp(mf[i].get_fam(), s) == 0)
		{
			printf(", квартира: %.1lf , налог: %.1lf ", mf[i].get_cost(), mf[i].nalog());
			sum += mf[i].nalog();
			fl = 1;
		}
	}
	for(int i = 0; i < kh; i++)
	{
		if(strcmp(mh[i].get_fam(), s) == 0)
		{
			printf(", дом: %.1lf , налог: %.1lf ", mh[i].get_space(), mh[i].nalog());
			sum += mh[i].nalog();
			fl = 1;
		}
	}
	for(int i = 0; i < kc; i++)
	{
		if(strcmp(mc[i].get_fam(), s) == 0)
		{
			printf(", машина: %.1lf , налог: %.1lf ", mc[i].get_power(), mc[i].nalog());
			sum+= mc[i].nalog();
			fl = 1;
		}
	}
	if(fl == 0)
	{
		printf("\nТакой человек не найден!");
	}
	else printf("\ncуммарный налог: %lf", sum);
}

bool have_flat(flat *m, char *s, int k)
{
	int fl = 0;
	for(int  i = 0; i< k; i++)
	{
		if(strcmp(m[i].get_fam(), s) == 0)
		{
			 fl = 1;;
		}
	}
	if (fl == 1) return true;
	else return false;
}

bool have_house(house *m, char *s, int  k)
{
	int fl = 0;
	for(int  i = 0; i< k; i++)
	{
		if(strcmp(m[i].get_fam(), s) == 0)
		{
			fl = 1;;
		}
	}
	if (fl == 1) return true;
	else return false;
}

bool have_car(car *m, char *s, int k)
{
	int fl = 0;
	for(int  i = 0; i< k; i++)
	{
		if(strcmp(m[i].get_fam(), s) == 0)
		{
			 fl = 1;;
		}
	}
	if (fl == 1) return true;
	else return false;
}

void find3(flat *mf, house *mh, car *mc, int kf, int kh, int kc)
{
	int kol = 0;
	for(int i = 0; i < kf; i++)
	{
		kol++;
		if(have_house(mh, mf[i].get_fam(), kh))
		{
			kol++;
		}
		if(have_car(mc, mf[i].get_fam(), kc))
		{
			kol++;
		}
		if(kol == 3) 
		{
			printf(" %s ", mf[i].get_fam());
		}
		kol = 0;
	}
}

void find2(flat *mf, house *mh, car *mc, int kf, int kh, int kc)
{
	int kol = 0;
	for(int i = 0; i < kf; i++)
	{
		kol++;
		if(have_house(mh, mf[i].get_fam(), kh))
		{
			kol++;
		}
		if(have_car(mc, mf[i].get_fam(), kc))
		{
			kol++;
		}
		if(kol == 2)
		{
			printf(" %s ", mf[i].get_fam());
		}
		kol = 0;
	}
	kol = 0;
	for(int i = 0; i < kh; i++)
	{
		kol++;
		if(have_car(mc, mh[i].get_fam(), kc))
		{
			if(!(have_flat(mf, mh[i].get_fam(), kf)))
				kol++;
		}
		if(kol == 2)
		{
			printf(" %s ", mh[i].get_fam());
		}
		kol = 0;
	}
}

void find1(flat *mf, house *mh, car *mc, int kf, int kh, int kc)
{
	for(int i = 0; i < kf; i++)
	{
		if(!(have_house(mh, mf[i].get_fam(), kh)) && !(have_car(mc, mf[i].get_fam(), kc)))
		{
			printf(" %s ", mf[i].get_fam());
		}
	}
	for(int i = 0; i < kh; i++)
	{
		if(!(have_flat(mf, mh[i].get_fam(), kf)) && !(have_car(mc, mh[i].get_fam(), kc)))
		{
			printf(" %s ", mh[i].get_fam());
		}
	}
	for(int i = 0; i < kc; i++)
	{
		if(!(have_house(mh, mc[i].get_fam(), kh)) && !(have_flat(mf, mc[i].get_fam(), kf)))
		{
			printf(" %s ", mc[i].get_fam());
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	FILE *f;
	char s[50];
	int kf = 0, kh = 0, kc = 0, kfam = 0;
	if ((f = fopen("f.txt", "r")) == NULL)
	{
		puts("ERROR");
		getch();
		return 0;
	}
	while(fgets(s, 200, f) != NULL)
	{
		if(strstr(s, "flat") != NULL)
		{
			kf++;
		}
		if(strstr(s, "house") != NULL)
		{
			kh++;
		}
		if(strstr(s, "car") != NULL)
		{
			kc++;
		}
		kfam++;
	}
	rewind(f);
	flat *fmas = new flat[kf];
	house *hmas = new house[kh];
	car *cmas = new car[kc];
	int fi = 0, hi = 0, ci = 0;
	int i = 0;
	char sfam[20];
	while(fscanf(f, "%s", s) != EOF)
	{
		if(strstr(s, "flat") == NULL && strstr(s, "house") == NULL && strstr(s, "car") == NULL)
		{
			strcpy(sfam, s);
		}
		if(strstr(s, "flat") != NULL)
		{
			fmas[fi] = flat(sfam, f);
			fi++;
		}
		if(strstr(s, "house") != NULL)
		{
			hmas[hi] = house(sfam, f);
			hi++;
		}
		if(strstr(s, "car") != NULL)
		{
			cmas[ci] = car(sfam, f);
			ci++;
		}
	}
	vivod(fmas, hmas, cmas, kf, kh, kc);
	char sur[20];
	puts("Введите фамилию:");
	scanf("%s", sur);
	find(fmas, hmas, cmas, kf, kh, kc, sur);
	puts("\nЛюди с 3 типами собственности:");
	find3(fmas, hmas, cmas, kf, kh, kc);
	puts("\nЛюди с 2 типами собственности:");
	find2(fmas, hmas, cmas, kf, kh, kc);
	puts("\nЛюди с 1 типом собственности:");
	find1(fmas, hmas, cmas, kf, kh, kc);
	getch();
	return 0;
}

