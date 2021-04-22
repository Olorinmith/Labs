// lab10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "conio.h"
#include "string.h"
#include <clocale>
#include "stdlib.h"
#include "math.h"
#pragma warning(disable:4996)

class name{
private:
	char nazv[20];
	int kol;
	double cost;
public:
	double sum_cost()
	{
		return (kol*1.0*cost);
	}
	char* get_nazv()
	{
		return nazv;
	}
	int get_kol()
	{
		return kol;
	}
	double get_cost()
	{
		return cost;
	}
	name()
	{
		strcpy(nazv, "\0");
		kol = 0;
		cost = 0;
	}
	name(FILE *f)
	{
		fscanf(f, "%s", &nazv);
		fscanf(f, "%d", &kol);
		fscanf(f, "%lf", &cost);
	}
};

class maker{
public:
	char firm[20];
	double prod_cost;
	int make_time;
	int lifetime(int t)
	{
		return (t - make_time);
	}
	maker()
	{
		strcpy(firm, "\0");
		prod_cost = 0;
		make_time = 0;
	}
	maker(FILE *f)
	{
		fscanf(f, "%s", &firm);
		fscanf(f, "%d", &make_time);
		fscanf(f, "%lf", &prod_cost);
	}
};

class storage{
protected:
	double store_cost;
	char store_name[20];
public:
	storage()
	{
		store_cost = 0;
		strcpy(store_name, "\0");
	}
	storage(FILE *f)
	{
		fscanf(f, "%s", &store_name);
		fscanf(f, "%lf", &store_cost);
	}
	char* get_store_name()
	{
		return store_name;
	}
	double get_store_cost()
	{
		return store_cost;
	}
};

class shop: public name, public maker, public storage{
public:
	double f1(int t)
	{
		return get_store_cost()*lifetime(t);
	}
	double f2(int t)
	{
		return (get_cost() - f1(t) - prod_cost);
	}
	shop()
	{};
	shop(FILE *f):name(f), maker(f), storage(f)
	{};
};

void vivod(shop *shm, int k)
{
	for(int i = 0; i < k; i++)
	{
		printf("Товар номер %d:\n", i+1);
		printf("Название товара: %s, Количество товара: %d, Цена товара: %7.3lf,\n          Стоимость всего товара: %7.3lf\n", shm[i].get_nazv(), shm[i].get_kol(), shm[i].get_cost(), shm[i].sum_cost());
		printf("Название фирмы: %s, Отпускная цена: %7.3lf, Дата изготовления: %d\n", shm[i].firm, shm[i].prod_cost, shm[i].make_time);
		printf("Название склада: %s, Стоимость хранения единицы товара в день: %7.3lf\n\n", shm[i].get_store_name(), shm[i].get_store_cost());
	}
}

void name_search(shop *shm1, shop *shm2, int k1, int k2)
{
	char s[20];
	int fl = 0;
	puts("Введите название товара:");
	scanf("%s", &s);
	for(int i = 0; i < k1; i++)
	{
		if(strcmp(shm1[i].get_nazv(), s) == 0)
		{
			printf("\nТовар %s в магазине 1 по цене %7.3lf\n", shm1[i].get_nazv(), shm1[i].get_cost());
			fl = 1;
		}
	}
	for(int i = 0; i < k2; i++)
	{
		if(strcmp(shm2[i].get_nazv(), s) == 0)
		{
			printf("\nТовар %s в магазине 2 по цене %7.3lf\n", shm2[i].get_nazv(), shm2[i].get_cost());
			fl = 1;
		}
	}
	if(fl == 0) puts("\nТакого товара нет\n");
}

int rent(shop *shm, int k)
{
	char s[20];
	int t = 0;
	puts("\nВведите название товара:");
	scanf("%s", &s);
	for(int i = 0; i < k; i++)
	{
		if(strcmp(shm[i].get_nazv(), s) == 0)
		{
			while (shm[i].get_cost() >= shm[i].prod_cost + shm[i].f1(t))
			{
				t++;
			}
		}
	}
	return t;
}

int sravn_mag(shop *shm1, shop *shm2, int k1, int k2)
{
	int kol1 = 0, kol2 = 0;
	for(int i = 0; i < k1; i++)
	{
		kol1 += shm1[i].get_kol();
	}
	for(int i = 0; i < k2; i++)
	{
		kol2 += shm2[i].get_kol();
	}
	if(kol1 > kol2) 
		return 1;
	else if(kol1  < kol2) 
		return 2;
	else return 3;
}

double cost_all(shop *shm1, shop *shm2, int k1, int k2)
{
	double kol1 = 0, kol2 = 0;
	for(int i = 0; i < k1; i++)
	{
		kol1 += shm1[i].sum_cost();
	}
	for(int i = 0; i < k2; i++)
	{
		kol2 += shm2[i].sum_cost();
	}
	return kol1 + kol2;
}

void sort(shop *shm, int k)
{
	shop tmp;
	int fl;
	do
	{
		fl = 0;
		for(int i = 0; i < k-1; i++)
		{
			if(shm[i].get_cost()>shm[i+1].get_cost())
			{
				tmp = shm[i];
				shm[i] = shm[i+1];
				shm[i+1] = tmp;
				fl = 1;
			}
		}
	}
	while(fl == 1);
}

void writetof(shop *shm, int k, FILE *f)
{
	for(int i = 0; i<k; i++)
	{
		fprintf(f, "%s %3d %8.3lf %s %3d %8.3lf %s %8.3lf\n", shm[i].get_nazv(), shm[i].get_kol(), shm[i].get_cost(), shm[i].firm, shm[i].make_time, shm[i].prod_cost, shm[i].get_store_name(), shm[i].get_store_cost());
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "");
	FILE *f1, *f2, *fe1, *fe2;
	int k1 = 0, k2 = 0, cfl;
	char s[50];
	if ((f1 = fopen("f1.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	if ((f2 = fopen("f2.txt", "r")) == NULL)
	{
		getch();
		return 0;
	}
	while(fgets(s, 200, f1) != NULL)
	{
		k1++;
	}
	while(fgets(s, 200, f2) != NULL)
	{
		k2++;
	}
	rewind(f1);
	rewind(f2);
	shop *shm1 = new shop[k1];
	for(int i = 0; i < k1; i++)
	{
		shm1[i] = shop(f1);
	}
	shop *shm2 = new shop[k2];
	for(int i = 0; i < k2; i++)
	{
		shm2[i] = shop(f2);
	}
	puts("Список товаров 1 магазина:\n");
	vivod(shm1, k1);
	puts("Список товаров 2 магазина:\n");
	vivod(shm2, k2);
	if ((fe1 = fopen("fe1.txt", "w")) == NULL)
	{
		getch();
		return 0;
	}
	if ((fe2 = fopen("fe2.txt", "w")) == NULL)
	{
		getch();
		return 0;
	}
	sort(shm1, k1);
	writetof(shm1, k1, fe1);
	sort(shm2, k2);
	writetof(shm2, k2, fe2);
	while (42)
	{
		puts("\nВыберите действие:\n 1 - поиск по названию\n 2 - рассчет рентабильности\n 3 - найти магазин с наибольшим количеством товара\n 4 - рассчет стоимости товара в каждом магазине\n 0 - выход из программы");
		scanf("%d", &cfl);
		system("cls");
		puts("Список товаров 1 магазина:\n");
		vivod(shm1, k1);
		puts("Список товаров 2 магазина:\n");
		vivod(shm2, k2);
		switch(cfl)
		{
			case 0:
				{
					return 0;
				}
			case 1:
				{
					name_search(shm1, shm2, k1, k2);
					break;
				}
			case 2:
				{
					int n;
					puts("\nВведите номер магазина:");
					scanf("%d", &n);
					if(n == 1) printf("\nРентабельное время хранения: %d", rent(shm1, k1));
					if(n == 2) printf("\nРентабельное время хранения: %d", rent(shm2, k2));
					break;
				}
			case 3:
				{
					int n = sravn_mag(shm1, shm2, k1, k2);
					if(n == 1) puts("\nВ магазине 1 товара больше");
					if(n == 2) puts("\nВ магазине 2 товара больше");
					if(n == 3) puts("\nВ магазинах одинаковое количество товара");
					break;
				}
			case 4:
				{
					double sum = cost_all(shm1, shm2, k1, k2);
					printf("Стоимость всего товара в обоих магазинах: %8.3lf", sum);
					break;
				}
		}
		puts("\nЧтобы вернуться в меню нажмите enter...");
		getch();		
		system("cls");
		puts("Список товаров 1 магазина:\n");
		vivod(shm1, k1);
		puts("Список товаров 2 магазина:\n");
		vivod(shm2, k2);
	}
	getch();
	return 0;
}

