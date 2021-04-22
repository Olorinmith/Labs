// lab12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "math.h"
#pragma warning(disable:4996)

class basic{
private:
	char post[20];
	char name[20];
public:
	virtual double zarplata() = 0;
	char* get_post()
	{
		return post;
	}
	char* get_name()
	{
		return name;
	}
	basic()
	{
		strcpy(post, "\0");
		strcpy(name, "\0");
	}
	basic(char *s, FILE *f)
	{
		strcpy(post, s);
		fscanf(f, "%s", name);
	}
};

class manager : public basic{
private:
	double kol;
public:
	double zarplata()
	{
		return (50000 + kol*0.05);
	}
	double get_kol()
	{
		return kol;
	}
	manager()
	{
		kol = 0;
	}
	manager(char *s, FILE *f):basic(s, f)
	{
		fscanf(f, "%lf", &kol);
	}
};

class engineer : public basic{
public:
	double zarplata()
	{
		return 80000;
	}
	engineer()
	{}
	engineer(char *s, FILE *f):basic(s, f)
	{}
};

class worker : public basic{
private:
	int kol1;
public:
	double zarplata()
	{
		return (300*kol1);
	}
	int get_kol1()
	{
		return kol1;
	}
	worker()
	{
		kol1 = 0;
	}
	worker(char *s, FILE *f):basic(s, f)
	{
		fscanf(f, "%d", &kol1);
	}
};

class supervisor : public basic{
private:
	int kol2;
public:
	double zarplata()
	{
		return (100000 + kol2*20000);
	}
	int get_kol2()
	{
		return kol2;
	}
	supervisor()
	{
		kol2 = 0;
	}
	supervisor(char *s, FILE *f):basic(s, f)
	{
		fscanf(f, "%d", &kol2);
	}
};

void vivod(manager *mas, int k)
{
	basic *b;
	for(int i = 0; i < k; i++)
	{
		b = &mas[i];
		printf("Должность: %s, Фамилия: %s\n   Количество продаж: %7.3lf, Зарплата: %7.3lf\n", b->get_post(), b->get_name(), mas[i].get_kol(), mas[i].zarplata());
	}
}

void vivod(engineer *mas, int k)
{
	basic *b;
	for(int i = 0; i < k; i++)
	{
		b = &mas[i];
		printf("Должность: %s, Фамилия: %s\n   Зарплата: %7.3lf\n", b->get_post(), b->get_name(), mas[i].zarplata());
	}
}

void vivod(worker *mas, int k)
{
	basic *b;
	for(int i = 0; i < k; i++)
	{
		b = &mas[i];
		printf("Должность: %s, Фамилия: %s\n   Количество отработанных часов: %d, Зарплата: %7.3lf\n", b->get_post(), b->get_name(), mas[i].get_kol1(), mas[i].zarplata());
	}
}

void vivod(supervisor mas)
{
	basic *b;
	b = &mas;
	printf("Должность: %s, Фамилия: %s\n   Количество заверщенных проектов: %d, Зарплата: %7.3lf\n", b->get_post(), b->get_name(), mas.get_kol2(), mas.zarplata());
}

double count(manager *mas, int k)
{
	basic *b;
	double sum = 0;
	for(int i = 0; i < k; i++)
	{
		b = &mas[i];
		sum+=b->zarplata();
	}
	return sum;
}

double count(engineer *mas, int k)
{
	basic *b;
	double sum = 0;
	for(int i = 0; i < k; i++)
	{
		b = &mas[i];
		sum+=b->zarplata();
	}
	return sum;
}

double count(worker *mas, int k)
{
	basic *b;
	double sum = 0;
	for(int i = 0; i < k; i++)
	{
		b = &mas[i];
		sum+=b->zarplata();
	}
	return sum;
}

int howmany(double h)
{
	double zp = 0;
	int kol = 0;
	while(zp <= h)
	{
		kol++;
		zp = 300*kol;
	}
	return kol;
}

void find(manager *mm, engineer *em, worker *wm, supervisor sv, int km, int ke, int kw, char *s)
{
	basic *b;
	int fl = 0;
	for(int i = 0; i < km; i++)
	{
		b = &mm[i];
		if(strcmp(b->get_name(), s) == 0)
		{
			printf("Должность: %s, Фамилия: %s\n   Количество продаж: %7.3lf, Зарплата: %7.3lf\n", b->get_post(), b->get_name(), mm[i].get_kol(), mm[i].zarplata());
			fl++;
		}
	}
	for(int i = 0; i < km; i++)
	{
		b = &em[i];
		if(strcmp(b->get_name(), s) == 0)
		{
			printf("Должность: %s, Фамилия: %s\n   Зарплата: %7.3lf\n", b->get_post(), b->get_name(), em[i].zarplata());
			fl++;
		}
	}
	for(int i = 0; i < km; i++)
	{
		b = &wm[i];
		if(strcmp(b->get_name(), s) == 0)
		{
			printf("Должность: %s, Фамилия: %s\n   Количество отработанных часов: %d, Зарплата: %7.3lf\n", b->get_post(), b->get_name(), wm[i].get_kol1(), wm[i].zarplata());
			fl++;
		}
	}
	if(strcmp(sv.get_name(), s) == 0)
	{
		printf("Должность: %s, Фамилия: %s\n   Количество заверщенных проектов: %d, Зарплата: %7.3lf\n", sv.get_post(), sv.get_name(), sv.get_kol2(), sv.zarplata());
		fl++;
	}
	if(fl == 0) puts("Работников с такой фамилией нет");
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	FILE *f;
	char s[50];
	int km = 0, ke = 0, kw = 0;
	if ((f = fopen("f.txt", "r")) == NULL)
	{
		puts("ERROR");
		getch();
		return 0;
	}
	while(fgets(s, 200, f) != NULL)
	{
		if(strstr(s, "manager") != NULL)
		{
			km++;
		}
		else if(strstr(s, "engineer") != NULL)
		{
			ke++;
		}
		else if(strstr(s, "worker") != NULL)
		{
			kw++;
		}
	}
	rewind(f);
	manager *mmas = new manager[km];
	engineer *emas = new engineer[ke];
	worker *wmas = new worker[kw];
	supervisor sv;
	int im = 0, ie = 0, iw = 0;
	while(fscanf(f, "%s", s) != EOF)
	{
		if(strstr(s, "manager") != NULL)
		{
			mmas[im] = manager(s, f);
			im++;
		}
		if(strstr(s, "engineer") != NULL)
		{
			emas[ie] = engineer(s, f);
			ie++;
		}
		if(strstr(s, "worker") != NULL)
		{
			wmas[iw] = worker(s, f);
			iw++;
		}
		if(strstr(s, "supervisor") != NULL)
		{
			sv = supervisor(s, f);
		}
	}
	vivod(sv);
	vivod(mmas, km);
	vivod(emas, ke);
	vivod(wmas, kw);
	double srm, sre, srw, summ, sume, sumw;
	summ = count(mmas, km);
	sume = count(emas, ke);
	sumw = count(wmas, kw);
	printf("Средняя зарплата менеджеров: %7.3lf\n", summ/km);
	printf("Средняя зарплата инженеров: %7.3lf\n", sume/ke);
	printf("Средняя зарплата рабочих: %7.3lf\n", sumw/kw);
	printf("Средняя зарплата всех работников: %7.3lf\n", (summ + sume + sumw + sv.zarplata()) / (km + ke + kw + 1));
	int hmt = howmany(summ/km);
	printf("Рабочий должен работать %d часов чтобы получить среднюю зарплату менеджера\n", hmt);
	char s1[20];
	puts("Введите фамилию:");
	scanf("%s", s1);
	find(mmas, emas, wmas, sv, km, ke, kw, s1);
	getch();
	return 0;
}

