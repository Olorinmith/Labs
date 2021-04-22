// lab7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "math.h"
#pragma warning(disable:4996)

class star{
private:
	int m;
	double r;
public:
	char name[20];
	int get_m()
	{
		return m;
	}
	double get_r()
	{
		return r;
	}
	double vol()
	{
		return (4 * 3.14 * r * r * r / 3);
	}
	double den()
	{
		return m * 1.0 / vol() * 100;
	}
	star(FILE *f)
	{
		fscanf(f, "%s", &name);
		fscanf(f, "%d", &m);
		fscanf(f, "%lf", &r);
	}
};

class galaxy{
private:
	int kol;
public:
	char name[20];
	int pa;
	int pb;
	int pc;
	int get_kol()
	{
		return kol;
	}
	double gmas(int ma, int mb, int mc)
	{
		return (kol * 1.0 * (pa * ma + pb * mb + pc * mc) / 100);
	}
	galaxy(FILE *f)
	{
		fscanf(f, "%s", &name);
		fscanf(f, "%d", &kol);
		fscanf(f, "%d", &pa);
		fscanf(f, "%d", &pb);
		fscanf(f, "%d", &pc);
	}
};

void vivod(star **mas, int k)
{
	for(int i = 0; i<k; i++)
	{
		printf("Название: %7s, Масса: %3d, Радиус: %7.3lf\nОбъем: %8.3lf, Плотность: %8.3lf\n\n", mas[i]->name, mas[i]->get_m(), mas[i]->get_r(), mas[i]->vol(), mas[i]->den());
	}
}

void vivodgal(galaxy **mas, int k, int ma, int mb, int mc)
{
	for(int i = 0; i<k; i++)
	{
		printf("Название: %10s, Масса: %7.3lf, Количество звезд: %d\nПроцент звезд типа А: %2d, В: %2d, С: %2d\n", mas[i]->name, mas[i]->gmas(ma, mb, mc), mas[i]->get_kol(), mas[i]->pa, mas[i]->pb, mas[i]->pc);
	}
}

void minrad(star **mas, int k)
{
	double min = mas[0]->get_r();
	for(int i = 0; i < k; i++)
	{
		if(mas[i]->get_r() < min)
		{
			min = mas[i]->get_r();
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i]->get_r() == min)
		{
			printf("Название: %7s, Масса: %3d, Радиус: %8.3lf\n Объем: %8.3lf, Плотность: %8.3lf\n", mas[i]->name, mas[i]->get_m(), mas[i]->get_r(), mas[i]->vol(), mas[i]->den());
		}
	}
}

void mingalm(galaxy **mas, int k, int ma, int mb, int mc)
{
	double min = mas[0]->gmas(ma, mb, mc);
	for(int i = 0; i < k; i++)
	{
		if(mas[i]->gmas(ma, mb, mc) < min)
		{
			min = mas[i]->gmas(ma, mb, mc);
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i]->gmas(ma, mb, mc) == min)
		{
			printf("Название: %10s, Масса: %7.3lf, Количество звезд: %d\n", mas[i]->name, mas[i]->gmas(ma, mb, mc), mas[i]->get_kol());
		}
	}
}

void mingalk(galaxy **mas, int k)
{
	double max = mas[0]->get_kol();
	for(int i = 0; i < k; i++)
	{
		if(mas[i]->get_kol() > max)
		{
			max = mas[i]->get_kol();
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i]->get_kol() == max)
		{
			printf("Название: %10s, Количество звезд: %d\n", mas[i]->name, mas[i]->get_kol());
		}
	}
}

void mingala(galaxy **mas, int k, int ma, int mb, int mc)
{
	double min = mas[0]->pa;
	for(int i = 0; i < k; i++)
	{
		if(mas[i]->pa < min)
		{
			min = mas[i]->pa;
		}
	}
	for (int i = 0; i<k; i++)
	{
		if(mas[i]->pa == min)
		{
			printf("Название: %10s, Масса: %7.3lf, Количество звезд: %d\nПроцент звезд типа А: %2d, В: %2d, С: %2d\n", mas[i]->name, mas[i]->gmas(ma, mb, mc), mas[i]->get_kol(), mas[i]->pa, mas[i]->pb, mas[i]->pc);
		}
	}
}

double srmas(star **mas, int k)
{
	int sum = 0;
	for(int i = 0; i < k; i++)
	{
		sum+=mas[i]->get_m();
	}
	return (sum*1.0 / k);
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	FILE *fs, *fg;
	int k = 0, kg = 0;
	char s[20], s1[30];
	double d, sm;
	if ((fs = fopen("fs.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	if ((fg = fopen("fg.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	while(fgets(s, 80, fs) != NULL)
	{
		k++;
	}
	while(fgets(s1, 120, fg) != NULL)
	{
		kg++;
	}
	rewind(fs);
	rewind(fg);
	star **mas = new star*[k];
	for(int i = 0; i< k; i++) mas[i] = new star(fs);
	galaxy **mg = new galaxy*[kg];
	for(int i = 0; i< kg; i++) mg[i] = new galaxy(fg);
	vivod(mas, k);
	puts("\nЗвезды с минимальным радиусом: ");
	minrad(mas, k);
	puts("\nВведите плотность:");
	scanf("%lf", &d);
	puts("\nЗвезды с плотностью больше введенной:");
	int fl = 0;
	for(int i = 0; i<k; i++)
	{
		if(mas[i]->den() > d)
		{
			printf("Название: %7s, Масса: %3d, Радиус: %8.3lf\n Объем: %8.3lf, Плотность: %8.3lf\n", mas[i]->name, mas[i]->get_m(), mas[i]->get_r(), mas[i]->vol(), mas[i]->den());
			fl = 1;
		}
	}
	if (fl == 0) printf("Таких нет!\n");
	sm = srmas(mas, k);
	printf("\nСредняя масса звезд: %8.3lf", sm);
	puts("\nЗвезды с массой больше средней:");
	for(int i = 0; i<k; i++)
	{
		if(mas[i]->get_m() > d)
		{
			printf("Название: %7s, Масса: %3d\n", mas[i]->name, mas[i]->get_m());
		}
	}
	puts("\nГалактики: ");
	vivodgal(mg, kg, mas[0]->get_m(), mas[1]->get_m(), mas[2]->get_m());
	puts("\nГалактики с минимальной массой: ");
	mingalm(mg, kg, mas[0]->get_m(), mas[1]->get_m(), mas[2]->get_m());
	puts("\nГалактики с минимальным процентом звезд типа А: ");
	mingala(mg, kg, mas[0]->get_m(), mas[1]->get_m(), mas[2]->get_m());
	puts("\nГалактики с максимальным количеством звезд: ");
	mingalk(mg, kg);
	fcloseall();
	getch();
	return 0;
}

